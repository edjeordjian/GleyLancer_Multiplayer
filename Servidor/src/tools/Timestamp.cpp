#include "Timestamp.h"
#include <ctime>
#include <bits/stdc++.h>

std::string timestampParaNombreLog(std::string pre_nombre) {
    return pre_nombre + getTimestamp((char*)"%Y_%m_%d___%H_%M_%S");
}

std::string timestampParaLog(char* tipo_log){
    std::string formato = std::string( "[%Y-%m-%d %H:%M:%S " ) +
                         std::string( tipo_log ) +
                         std::string( "] " );

    return getTimestamp( (char*) formato.c_str() );
}

std::string getTimestamp(char* formato) {
    std::time_t tiempo_epoch = std::time(nullptr);
    std::stringstream stream;
    stream << std::put_time( std::localtime(&tiempo_epoch), formato );
    return stream.str();
}
