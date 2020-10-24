#include "ConstantesMenu.h"

static std::string ip_servidor;
static std::string puerto_servidor;

void setIP(std::string ip){
    ip_servidor = ip;
}

char* getIPServidor() {
    return (char*) ip_servidor.c_str();
}

const char* getIPServidorCte() {
    return ip_servidor.c_str();
}


void setPuerto(std::string puerto){
    if (std::strtol(puerto.c_str(), NULL, 10) > 1024
        && std::strtol(puerto.c_str(),  NULL, 10) < 65536) {
        puerto_servidor = puerto;
    }
}

char* getPuertoServidor() {
    return (char*) puerto_servidor.c_str();
}

std::string usuario;
std::string pass;
std::string pass_asteriscos;

void setUsuario(std::string n, bool trim){
    usuario = n;

    if(trim){
        usuario.pop_back();
    }
}

char *getUsuario(){
    return (char *) usuario.c_str();
}

void setPass(std::string n, bool trim){
    pass = n;
    pass_asteriscos = "";

    for(size_t i = 0; i < pass.size(); i++){
        pass_asteriscos += "*";
    }

    if(trim){
        pass.pop_back();
        pass_asteriscos.pop_back();
    }
}

char *getPass(){
    return (char *) pass.c_str();
}

char *getPassAsteriscos(){
    return (char *)pass_asteriscos.c_str();
}