#ifndef SERVIDOR_LOG_H
#define SERVIDOR_LOG_H

#include <iostream>
#include <string>
#include "Timestamp.h"
#include "constantes/ConstantesLog.h"

extern void setNombreLog();
extern std::string getNombreLog();
extern bool setTipoLog(int tipo);
extern int getTipoLog();
extern void setNombreLogAux();
extern bool logExiste(std::string ruta);

extern bool loguearInfo(std::string msj_info);
extern bool loguearDebug(std::string msj_debug);
extern bool loguearError(std::string msj_error);
extern bool loguear(std::string msj, int tipo);

#endif //SERVIDOR_LOG_H
