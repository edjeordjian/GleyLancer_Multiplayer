#ifndef SERVIDOR_TIMESTAMP_H
#define SERVIDOR_TIMESTAMP_H

#include <bits/stdc++.h>

extern std::string timestampParaLog(char* tipo_log);
extern std::string timestampParaNombreLog(std::string pre_nombre);

extern std::string getTimestamp(char* formato);

#endif //SERVIDOR_TIMESTAMP_H
