#include "ConstantesJson.h"

static std::string RUTA_CONFIG;
static std::string PUERTO_DEFECTO = "3333";

static std::string TIPO_ENEMIGO_1;
static std::string CANTIDAD_ENEMIGO_1_1;
static std::string CANTIDAD_ENEMIGO_1_2;
static std::string CANTIDAD_ENEMIGO_1_3;
static std::string TIPO_ENEMIGO_2;
static std::string CANTIDAD_ENEMIGO_2_1;
static std::string CANTIDAD_ENEMIGO_2_2;
static std::string CANTIDAD_ENEMIGO_2_3;
static int ANCHO_ENEMIGO_1;
static int ALTO_ENEMIGO_1;
static int ANCHO_ENEMIGO_2;
static int ALTO_ENEMIGO_2;
static int TAM_ANCHO_ENEMIGO_1;
static int TAM_ANCHO_ENEMIGO_2;
static int TAM_ALTO_ENEMIGO_1;
static int TAM_ALTO_ENEMIGO_2;

static std::vector<std::string> NOMBRES_USUARIOS;
static std::vector<std::string> PASSWORDS;

void setRutaConfig(std::string ruta){
    RUTA_CONFIG = ruta;
}

char* getRutaConfig(){
    return (char*) RUTA_CONFIG.c_str();
}

void setTipoEnemigo1(std::string tipo) {
    TIPO_ENEMIGO_1 = tipo;
    ANCHO_ENEMIGO_1 = (int) anchos_enemigo[tipo];
    ALTO_ENEMIGO_1 = (int) altos_enemigos[tipo];
    TAM_ALTO_ENEMIGO_1 = (int) tam_altos_enemigos[tipo];
    TAM_ANCHO_ENEMIGO_1 = (int) tam_anchos_enemigos[tipo];
}

void setTipoEnemigo2(std::string tipo) {
    TIPO_ENEMIGO_2 = tipo;
    ANCHO_ENEMIGO_2 = (int) anchos_enemigo[tipo];
    ALTO_ENEMIGO_2 = (int) altos_enemigos[tipo];
    TAM_ALTO_ENEMIGO_2 = (int) tam_altos_enemigos[tipo];
    TAM_ANCHO_ENEMIGO_2 = (int) tam_anchos_enemigos[tipo];
}

std::string getTipoEnemigo1() {
    return TIPO_ENEMIGO_1;
}

void setCantEnemigo1Nivel1(std::string tipo) {
    CANTIDAD_ENEMIGO_1_1 = tipo;

}

void setCantEnemigo1Nivel2(std::string tipo){
    CANTIDAD_ENEMIGO_1_2 = tipo;
}

void setCantEnemigo1Nivel3(std::string tipo){
    CANTIDAD_ENEMIGO_1_3 = tipo;
}


int getCantEnemigo1Nivel1() {
    return atoi((char *) CANTIDAD_ENEMIGO_1_1.c_str());
}

int getCantEnemigo1Nivel2(){
    return atoi((char *) CANTIDAD_ENEMIGO_1_2.c_str());
}

int getCantEnemigo1Nivel3(){
    return atoi((char *) CANTIDAD_ENEMIGO_1_3.c_str());
}

std::string getTipoEnemigo2() {
    return TIPO_ENEMIGO_2;
}

void setCantEnemigo2Nivel1(std::string tipo) {
    CANTIDAD_ENEMIGO_2_1 = tipo;
}

void setCantEnemigo2Nivel2(std::string tipo) {
    CANTIDAD_ENEMIGO_2_2 = tipo;
}

void setCantEnemigo2Nivel3(std::string tipo) {
    CANTIDAD_ENEMIGO_2_3 = tipo;
}

int getCantEnemigo2Nivel1() {
    return atoi((char *) CANTIDAD_ENEMIGO_2_1.c_str());
}

int getCantEnemigo2Nivel2() {
    return atoi((char *) CANTIDAD_ENEMIGO_2_2.c_str());
}

int getCantEnemigo2Nivel3() {
    return atoi((char *) CANTIDAD_ENEMIGO_2_3.c_str());
}

int getTamAltoPersonaje(){
    return TAM_ALTO_PERSONAJE;
}
int getTamAnchoPersonaje(){
    return TAM_ANCHO_PERSONAJE;
}
int getTamAltoProyectil(){
    return TAM_ALTO_PROYECTIL;
}
int getTamAnchoProyectil(){
    return TAM_ANCHO_PROYECTIL;
}

int getCantMaxEnemigos() {
    return atoi((char *) CANTIDAD_ENEMIGO_MAX.c_str());
}

int getAnchoEnemigo1() {
    return ANCHO_ENEMIGO_1;
}

int getAnchoEnemigo2() {
    return ANCHO_ENEMIGO_2;
}

int getAltoEnemigo1() {
    return ALTO_ENEMIGO_1;
}

int getAltoEnemigo2() {
    return ALTO_ENEMIGO_2;
}

int getTamAnchoEnemigo1() {
    return TAM_ANCHO_ENEMIGO_1;
}

int getTamAnchoEnemigo2() {
    return TAM_ANCHO_ENEMIGO_2;
}

int getTamAltoEnemigo1() {
    return TAM_ALTO_ENEMIGO_1;
}

int getTamAltoEnemigo2() {
    return TAM_ALTO_ENEMIGO_2;
}

std::string getPuerto(){
    return PUERTO_DEFECTO;
}

void setPuerto(std::string puerto_nuevo){
    PUERTO_DEFECTO = puerto_nuevo;
}

void agregarNombreUsuario(std::string user){
    NOMBRES_USUARIOS.push_back(user);
}

void agregarPass(std::string pass){
    PASSWORDS.push_back(pass);
}

std::vector<std::string> getNombresUsuarios(){
    return NOMBRES_USUARIOS;
}
std::vector<std::string> getPasswords(){
    return PASSWORDS;
}

size_t getCantidadUsuarios() {
    if ( NOMBRES_USUARIOS.size() >= N_JUGADORES_MAX ) return N_JUGADORES_MAX;
    return NOMBRES_USUARIOS.size();
}


