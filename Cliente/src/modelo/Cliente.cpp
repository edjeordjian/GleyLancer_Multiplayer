#include "Cliente.h"



Cliente::Cliente()
        : fd{FD_DESCONECTADO}, esta_conectado{false}, mutex_conexion() {

}


Cliente::~Cliente(){
}


int Cliente::getFd(){
    return this->fd;
}

void Cliente::conectarse(const char* host, const char* puerto){
    struct addrinfo hints;
    struct addrinfo* res;
    memset(&hints, 0, sizeof (struct addrinfo));
    hints.ai_family = AF_INET; 			/* IPv4 (o AF_INET6 para IPv6)     */
    hints.ai_socktype = SOCK_STREAM; 	/* TCP  (o SOCK_DGRAM para UDP)    */
    hints.ai_flags = 0;  				/* None (o AI_PASSIVE para server) */

    /*  getaddrinfo retorna una **lista** de direcciones. Hay que iterarla
     *  para encontrar la que mejor se ajusta.
     *  (generalmente la primera direccion es la mejor, pero dependera de
     *  cada caso)
     *  En este caso voy a probar cada direccion posible. La primera que
     *	funcione sera la que se usara por el resto del programa.
     */
    //La lista de direcciones se guarda en "res"
    int s = ::getaddrinfo(host, puerto, &hints, &res);
    if (s != 0) {
        loguearError(LOG_ERROR_GETADDR);
        //se utiliza
        throw LOG_ERROR_GETADDR;
    }

    struct addrinfo* ptr;

    for (ptr = res; ptr != NULL and !this->esta_conectado; ptr = ptr->ai_next) {
        /*  Creamos el socket definiendo la familia (deberia ser AF_INET IPv4),
         *  el tipo de socket (deberia ser SOCK_STREAM TCP) y el protocolo (0)
         */
        this->fd = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);
        if (this->fd == FD_DESCONECTADO) {
            loguearError(LOG_ERROR_DATOS_INVALIDOS);

        } else {

            /* Se pone un timeout para la conexión, por si se pasa una IP
           * inválida.*/
            struct timeval valor_to;
            valor_to.tv_sec = SEGUNDOS_TIMEOUT_CONNECT;
            valor_to.tv_usec = MICROSEGUNDOS_TIMEOUT_CONNECT;
            ::setsockopt(this->fd, SOL_SOCKET, SO_SNDTIMEO, (const char*)&valor_to, sizeof valor_to);

            /* Nos conectamos al server
               ai_addr encapsula la IP y el puerto del server.
               La estructura es automaticamente creada por getaddrinfo */
            s = ::connect(this->fd, ptr->ai_addr, ptr->ai_addrlen);

            valor_to.tv_sec = SEGUNDOS_TIMEOUT_NORMAL;
            valor_to.tv_usec = MICROSEGUNDOS_TIMEOUT_NORMAL;
            ::setsockopt(this->fd, SOL_SOCKET, SO_SNDTIMEO, (const char*)&valor_to, sizeof valor_to);

            int flags = 1;
            setsockopt(s, IPPROTO_TCP, TCP_NODELAY, (void *)&flags, sizeof(flags));

            if (s == FD_DESCONECTADO) {
                loguearError(LOG_ERROR_CONEXION_CLIENTE );
                ::close(this->fd);
            }
            this->esta_conectado = (s != FD_DESCONECTADO);
        }
    }
    /* Finalmente, la **lista** de direcciones debe ser liberada */
    freeaddrinfo(res);

    if (! this->esta_conectado) {
        this->fd = FD_DESCONECTADO;
    }

}

void Cliente::cerrarConexion() {
    if (this->fd != FD_DESCONECTADO){
        ::shutdown(this->fd, SHUT_RDWR);
        ::close(this->fd);

        if(this->esta_conectado){
            loguearInfo(LOG_CONEXION_CERRADA);
        }

        this->esta_conectado = false;
        this->fd = FD_DESCONECTADO;
    }
}

bool Cliente::estaActivo() {
    return this->esta_conectado;
}

int Cliente::recibir(void* buffer){
    int msg_length;
    std::uint16_t msg_len_ptr[1] {0};
    //Veo cuantos bytes me va a mandar el Cliente
    int cantidad_de_bytes = Cliente::bytesARecibir(msg_len_ptr);
    bool socket_esta_conectado = (cantidad_de_bytes > 0);

    if (socket_esta_conectado){
        msg_length = ::ntohs(*msg_len_ptr);

    } else {
        return cantidad_de_bytes;
    }

    long int recv_bytes = 0;
    long int s = 0;
    //Recibo los bytes que me manda el Clientee y los guardo en el buffer
    while (socket_esta_conectado and (recv_bytes < msg_length)){
        //Casteo el buffer a char* para que el offset sea de a 1 byte
        /*  s: representa la cantidad de bytes recibidos con la funcion recibir (sera menor o igual a msg_length,
         *  en caso de que sea 0 significa que el servidor se deconecto (tiro del cable), en caso de que sea -1
         *  significa que hubo un error (en nuestro caso consideramos que el unico error posible es timeout)
         */

        s = ::recv(this->fd, &((char*)buffer)[recv_bytes],
                   (unsigned long)(msg_length - recv_bytes), 0);

        if (s <= 0) {
            socket_esta_conectado = false;
            this->mutex_conexion.lock();
            if (this->fd != FD_DESCONECTADO){
                loguearError(LOG_ERROR_RECV);
            }
            this->mutex_conexion.unlock();

            //Guardo y sumo la cantidad de bytes recibidos
        } else {
            recv_bytes += s;
        }
    }

    if (socket_esta_conectado){
        //La cantidad de bytes que me mando el Cliente
        return (int)recv_bytes;
    }

    return (int)s;
}

int Cliente::bytesARecibir(void* amount_of_bytes){
    bool socket_esta_conectado = true;
    long int recv_bytes = 0;
    long int s = 0;
    //Queremos recibir 2 bytes
    int bytes_a_recibir = sizeof(std::uint16_t);

    //El Cliente en su mensaje manda en los primeros 4 bytes el uint16_t que
    //representa la longitud del resto del mensaje en bytes que nos quiere mandar
    while (socket_esta_conectado and (recv_bytes < bytes_a_recibir)){
        s = ::recv(this->fd, &((char*)amount_of_bytes)[recv_bytes],
                   (unsigned long)(bytes_a_recibir - recv_bytes), 0);

        /*
            if (s == -1) { 						//Hubo un error
                ::shutdown(this->fd, SHUT_RDWR);
                ::close(this->fd);
                throw ("Error en el receive" + std::string(strerror(errno)) + "\n");
            } else if (s == 0) { 				//Se cerró la conexion
                socket_esta_conectado = false;
             */
        if (s <= 0) {
            socket_esta_conectado = false;
            this->mutex_conexion.lock();
            if (this->fd != FD_DESCONECTADO) {
                loguearError(LOG_ERROR_RECV);
            }
            this->mutex_conexion.unlock();

        } else {
            recv_bytes += s;
        }
    }

    if (socket_esta_conectado){
        //La cantidad de bytes que me mandó el Cliente
        return (int)recv_bytes;
    }

    return (int)s;
}

long int Cliente::enviar(uint16_t* input){
    long int s;
    bool socket_connected = true;
    unsigned long bytes_sent = 0;
    uint16_t mensaje = htons(*input);
    size_t tam = sizeof(uint16_t);

    while (bytes_sent < tam and socket_connected) {
        s = ::send(this->fd, &((char*)&mensaje)[bytes_sent],
                   (tam - bytes_sent), MSG_NOSIGNAL);
        if (s <= 0) { // error
            socket_connected = false;
            this->mutex_conexion.lock();
            if (this->fd != FD_DESCONECTADO){
                loguearError(LOG_ERROR_SEND);
            }
            this->mutex_conexion.unlock();

        } else {
            bytes_sent += (unsigned long)s;
        }
    }

    if (socket_connected){
        //La cantidad de bytes que me mandó el Cliente
        return (int)bytes_sent;
    }

    return (int)s;
}

void Cliente::desconectarse() {
    this->mutex_conexion.lock();
    if (this->estaActivo()) {
        this->cerrarConexion();
    }
    this->mutex_conexion.unlock();
}
