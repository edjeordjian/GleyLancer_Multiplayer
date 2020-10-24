#include "HiloEnviar.h"

HiloEnviar::HiloEnviar(ColaProtegida<std::string> *q, Servidor *s)
        : cola_enviar{q},
          servidor{s} {
}

HiloEnviar::~HiloEnviar() {
    if (this->estaActivo()) {
        this->matar();
    }
}

void HiloEnviar::ejecutar() {
    if (!this->estaActivo()) {
        this->hilo = std::thread(&HiloEnviar::protocoloEnviar, this);
    }
}

void HiloEnviar::matar() {
    if (this->estaActivo()) {
        this->cola_enviar->encolar(MSJ_COLA_HILO_ENVIAR);
        this->hilo.join();
    }
}

bool HiloEnviar::estaActivo() {
    return this->hilo.joinable();
}

void HiloEnviar::protocoloEnviar() {
    std::string msg;
    char send_msg[4096]{0}; //No le puedo mandar directamente el string, debo enviar array de chars
    std::uint16_t response_length = 0;
    std::uint16_t aux = 0;
    while (msg != MSJ_COLA_HILO_ENVIAR && *this->peer_fd != FD_DEFECTO) {
        msg = this->cola_enviar->desencolar(MSJ_COLA_VACIA);

        while (msg == MSJ_COLA_VACIA) {
            std::this_thread::sleep_for(std::chrono::milliseconds(MILISEG_COLA_VACIA));
            msg = this->cola_enviar->desencolar(MSJ_COLA_VACIA);
        }

        std::copy(msg.begin(), msg.end(), (char *) send_msg);
        send_msg[msg.length()] = '\0';
        response_length = (std::uint16_t) msg.length();
        aux = ::htons((uint16_t) msg.length());

        if (*this->peer_fd != FD_DEFECTO and msg != MSJ_COLA_VACIA) {

            /* Riesgo potencial de race condition:
            *  el hilo recibir me setea el fd en -1 CUANDO YA ENTRÉ A ESTE MÉTODO...
            *  lo que pasaría es que se le intentaría
            *  enviar a un fd inválido un mensaje, y ese intento fallaría.
            */

            this->servidor->enviarMensajeCliente(*(this->peer_fd), &aux, sizeof(response_length));
            this->servidor->enviarMensajeCliente(*(this->peer_fd), send_msg, response_length);
        }
    }
}

void HiloEnviar::setFD(int *peer) {
    this->peer_fd = peer;
}
