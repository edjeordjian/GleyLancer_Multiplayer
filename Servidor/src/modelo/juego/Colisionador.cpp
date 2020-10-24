#include "Colisionador.h"

Colisionador::Colisionador() {

}

Colisionador::~Colisionador() {

}

bool Colisionador::hayColisionesInicialesDeEnemigos(Enemigo *nuevo_enemigo, std::vector<Enemigo *> enemigos) {
    bool existeColision = false;
    if (enemigos.empty()) {
        return existeColision;
    }
    unsigned long cantidad_posiciones = enemigos.size();
    for (unsigned long i = 0; i < cantidad_posiciones; ++i) {
        existeColision = existeColision || hayColision(nuevo_enemigo, enemigos[i]);
    }
    return existeColision;

}

bool Colisionador::hayColision(IChocable *obj1, IChocable *obj2) {

    double vertices_1[4];
    double vertices_2[4];

    double pos1[2];
    double pos2[2];

    pos1[0] = obj1->getPosX();
    pos1[1] = obj1->getPosY();
    pos2[0] = obj2->getPosX();
    pos2[1] = obj2->getPosY();

    obtenerVertices(vertices_1, pos1, obj1->getAncho(), obj1->getAlto());
    obtenerVertices(vertices_2, pos2, obj2->getAncho(), obj2->getAlto());

    bool colision_en_x = vertices_1[0] < vertices_2[1] && vertices_1[1] > vertices_2[0];
    bool colision_en_y = vertices_1[2] < vertices_2[3] && vertices_1[3] > vertices_2[2];

    return colision_en_x && colision_en_y;

}


void Colisionador::obtenerVertices(double *vertices, const double *pos_inicial, int ancho, int alto) {
    vertices[0] = pos_inicial[0];
    vertices[1] = pos_inicial[0] + ancho;
    vertices[2] = pos_inicial[1];
    vertices[3] = pos_inicial[1] + alto;
}
