#ifndef CLIENTE_CONSTANTESPERSONAJE_H
#define CLIENTE_CONSTANTESPERSONAJE_H

#include <string>
#include <vector>


/// PERSONAJE ///
static constexpr unsigned int ANCHO_PERSONAJE = 90;
static constexpr unsigned int ALTO_PERSONAJE = 50;

static constexpr unsigned int ANCHO_PERSONAJE_UI = 180;
static constexpr unsigned int ALTO_PERSONAJE_UI = 80;

static constexpr unsigned int ANCHO_ESCUDO_PERSONAJE = 120;
static constexpr unsigned int ALTO_ESCUDO_PERSONAJE = 90;

static constexpr int X_PERSONAJE_DEFAULT = 0;
static constexpr int Y_PERSONAJE_DEFAULT = 100;
static const std::string PRE_POSICION_JUGADOR = "Pos_Jugador";

static constexpr int DIRECCION_PERSONAJE_DERECHA = 2;

static constexpr int PERSONAJE_UI_MUERTO = 0;
static constexpr int PERSONAJE_UI_VIVO = 1;
static constexpr int PERSONAJE_UI_DESCONECTADO = 2;
static constexpr int PERSONAJE_UI_DISPARANDO = 3;
static constexpr int PERSONAJE_UI_DISPARANDO_2 = 4;
static constexpr int PERSONAJE_UI_IMPACTADO = 5;
static constexpr int PERSONAJE_UI_GAME_OVER = 5;

static constexpr int POS_VEC_TEXTURA = 6;

static constexpr char *RUTA_PERSONAJE_1_DER_CLARO = (char *) ("../data/imgs/personajes/p1/p1_l.png");
static constexpr char *RUTA_PERSONAJE_1_DER_NORMAL = (char *) ("../data/imgs/personajes/p1/p1_ll.png");
static constexpr char *RUTA_PERSONAJE_1_DER_OSCURO = (char *) ("../data/imgs/personajes/p1/p1_lll.png");
static constexpr char *RUTA_PERSONAJE_1_DER_DISP1 = (char *) ("../data/imgs/personajes/p1/p1_disp1.png");
static constexpr char *RUTA_PERSONAJE_1_DER_DISP2 = (char *) ("../data/imgs/personajes/p1/p1_disp2.png");
static constexpr char *RUTA_PERSONAJE_1_DER_DANIADO = (char *) ("../data/imgs/personajes/p1/p1_damaged.png");
static constexpr char *RUTA_PERSONAJE_1_ARR_CLARO = (char *) ("../data/imgs/personajes/p1/p1_l_arr.png");
static constexpr char *RUTA_PERSONAJE_1_ARR_NORMAL = (char *) ("../data/imgs/personajes/p1/p1_ll_arr.png");
static constexpr char *RUTA_PERSONAJE_1_ARR_OSCURO = (char *) ("../data/imgs/personajes/p1/p1_lll_arr.png");
static constexpr char *RUTA_PERSONAJE_1_ARR_DISP1 = (char *) ("../data/imgs/personajes/p1/p1_disp1_arr.png");
static constexpr char *RUTA_PERSONAJE_1_ARR_DISP2 = (char *) ("../data/imgs/personajes/p1/p1_disp2_arr.png");
static constexpr char *RUTA_PERSONAJE_1_ARR_DANIADO = (char *) ("../data/imgs/personajes/p1/p1_damaged_arr.png");
static constexpr char *RUTA_PERSONAJE_1_ABA_CLARO = (char *) ("../data/imgs/personajes/p1/p1_l_aba.png");
static constexpr char *RUTA_PERSONAJE_1_ABA_NORMAL = (char *) ("../data/imgs/personajes/p1/p1_ll_aba.png");
static constexpr char *RUTA_PERSONAJE_1_ABA_OSCURO = (char *) ("../data/imgs/personajes/p1/p1_lll_aba.png");
static constexpr char *RUTA_PERSONAJE_1_ABA_DISP1 = (char *) ("../data/imgs/personajes/p1/p1_disp1_aba.png");
static constexpr char *RUTA_PERSONAJE_1_ABA_DISP2 = (char *) ("../data/imgs/personajes/p1/p1_disp2_aba.png");
static constexpr char *RUTA_PERSONAJE_1_ABA_DANIADO = (char *) ("../data/imgs/personajes/p1/p1_damaged_aba.png");
static constexpr char *RUTA_PERSONAJE_1_ESCUDO = (char *) ("../data/imgs/personajes/p1/p1_escudo.png");

static constexpr char *RUTA_PERSONAJE_2_DER_CLARO = (char *) ("../data/imgs/personajes/p2/p2_l.png");
static constexpr char *RUTA_PERSONAJE_2_DER_NORMAL = (char *) ("../data/imgs/personajes/p2/p2_ll.png");
static constexpr char *RUTA_PERSONAJE_2_DER_OSCURO = (char *) ("../data/imgs/personajes/p2/p2_lll.png");
static constexpr char *RUTA_PERSONAJE_2_DER_DISP1 = (char *) ("../data/imgs/personajes/p2/p2_disp1.png");
static constexpr char *RUTA_PERSONAJE_2_DER_DISP2 = (char *) ("../data/imgs/personajes/p2/p2_disp2.png");
static constexpr char *RUTA_PERSONAJE_2_DER_DANIADO = (char *) ("../data/imgs/personajes/p2/p2_damaged.png");
static constexpr char *RUTA_PERSONAJE_2_ARR_CLARO = (char *) ("../data/imgs/personajes/p2/p2_l_arr.png");
static constexpr char *RUTA_PERSONAJE_2_ARR_NORMAL = (char *) ("../data/imgs/personajes/p2/p2_ll_arr.png");
static constexpr char *RUTA_PERSONAJE_2_ARR_OSCURO = (char *) ("../data/imgs/personajes/p2/p2_lll_arr.png");
static constexpr char *RUTA_PERSONAJE_2_ARR_DISP1 = (char *) ("../data/imgs/personajes/p2/p2_disp1_arr.png");
static constexpr char *RUTA_PERSONAJE_2_ARR_DISP2 = (char *) ("../data/imgs/personajes/p2/p2_disp2_arr.png");
static constexpr char *RUTA_PERSONAJE_2_ARR_DANIADO = (char *) ("../data/imgs/personajes/p2/p2_damaged_arr.png");
static constexpr char *RUTA_PERSONAJE_2_ABA_CLARO = (char *) ("../data/imgs/personajes/p2/p2_l_aba.png");
static constexpr char *RUTA_PERSONAJE_2_ABA_NORMAL = (char *) ("../data/imgs/personajes/p2/p2_ll_aba.png");
static constexpr char *RUTA_PERSONAJE_2_ABA_OSCURO = (char *) ("../data/imgs/personajes/p2/p2_lll_aba.png");
static constexpr char *RUTA_PERSONAJE_2_ABA_DISP1 = (char *) ("../data/imgs/personajes/p2/p2_disp1_aba.png");
static constexpr char *RUTA_PERSONAJE_2_ABA_DISP2 = (char *) ("../data/imgs/personajes/p2/p2_disp2_aba.png");
static constexpr char *RUTA_PERSONAJE_2_ABA_DANIADO = (char *) ("../data/imgs/personajes/p2/p2_damaged_aba.png");
static constexpr char *RUTA_PERSONAJE_2_ESCUDO = (char *) ("../data/imgs/personajes/p2/p2_escudo.png");

static constexpr char *RUTA_PERSONAJE_3_DER_CLARO = (char *) ("../data/imgs/personajes/p3/p3_l.png");
static constexpr char *RUTA_PERSONAJE_3_DER_NORMAL = (char *) ("../data/imgs/personajes/p3/p3_ll.png");
static constexpr char *RUTA_PERSONAJE_3_DER_OSCURO = (char *) ("../data/imgs/personajes/p3/p3_lll.png");
static constexpr char *RUTA_PERSONAJE_3_DER_DISP1 = (char *) ("../data/imgs/personajes/p3/p3_disp1.png");
static constexpr char *RUTA_PERSONAJE_3_DER_DISP2 = (char *) ("../data/imgs/personajes/p3/p3_disp2.png");
static constexpr char *RUTA_PERSONAJE_3_DER_DANIADO = (char *) ("../data/imgs/personajes/p3/p3_damaged.png");
static constexpr char *RUTA_PERSONAJE_3_ARR_CLARO = (char *) ("../data/imgs/personajes/p3/p3_l_arr.png");
static constexpr char *RUTA_PERSONAJE_3_ARR_NORMAL = (char *) ("../data/imgs/personajes/p3/p3_ll_arr.png");
static constexpr char *RUTA_PERSONAJE_3_ARR_OSCURO = (char *) ("../data/imgs/personajes/p3/p3_lll_arr.png");
static constexpr char *RUTA_PERSONAJE_3_ARR_DISP1 = (char *) ("../data/imgs/personajes/p3/p3_disp1_arr.png");
static constexpr char *RUTA_PERSONAJE_3_ARR_DISP2 = (char *) ("../data/imgs/personajes/p3/p3_disp2_arr.png");
static constexpr char *RUTA_PERSONAJE_3_ARR_DANIADO = (char *) ("../data/imgs/personajes/p3/p3_damaged_arr.png");
static constexpr char *RUTA_PERSONAJE_3_ABA_CLARO = (char *) ("../data/imgs/personajes/p3/p3_l_aba.png");
static constexpr char *RUTA_PERSONAJE_3_ABA_NORMAL = (char *) ("../data/imgs/personajes/p3/p3_ll_aba.png");
static constexpr char *RUTA_PERSONAJE_3_ABA_OSCURO = (char *) ("../data/imgs/personajes/p3/p3_lll_aba.png");
static constexpr char *RUTA_PERSONAJE_3_ABA_DISP1 = (char *) ("../data/imgs/personajes/p3/p3_disp1_aba.png");
static constexpr char *RUTA_PERSONAJE_3_ABA_DISP2 = (char *) ("../data/imgs/personajes/p3/p3_disp2_aba.png");
static constexpr char *RUTA_PERSONAJE_3_ABA_DANIADO = (char *) ("../data/imgs/personajes/p3/p3_damaged_aba.png");
static constexpr char *RUTA_PERSONAJE_3_ESCUDO = (char *) ("../data/imgs/personajes/p3/p3_escudo.png");

static constexpr char *RUTA_PERSONAJE_4_DER_CLARO = (char *) ("../data/imgs/personajes/p4/p4_l.png");
static constexpr char *RUTA_PERSONAJE_4_DER_NORMAL = (char *) ("../data/imgs/personajes/p4/p4_ll.png");
static constexpr char *RUTA_PERSONAJE_4_DER_OSCURO = (char *) ("../data/imgs/personajes/p4/p4_ll.png");
static constexpr char *RUTA_PERSONAJE_4_DER_DISP1 = (char *) ("../data/imgs/personajes/p4/p4_disp1.png");
static constexpr char *RUTA_PERSONAJE_4_DER_DISP2 = (char *) ("../data/imgs/personajes/p4/p4_disp2.png");
static constexpr char *RUTA_PERSONAJE_4_DER_DANIADO = (char *) ("../data/imgs/personajes/p4/p4_damaged.png");
static constexpr char *RUTA_PERSONAJE_4_ARR_CLARO = (char *) ("../data/imgs/personajes/p4/p4_l_arr.png");
static constexpr char *RUTA_PERSONAJE_4_ARR_NORMAL = (char *) ("../data/imgs/personajes/p4/p4_ll_arr.png");
static constexpr char *RUTA_PERSONAJE_4_ARR_OSCURO = (char *) ("../data/imgs/personajes/p4/p4_ll_arr.png");
static constexpr char *RUTA_PERSONAJE_4_ARR_DISP1 = (char *) ("../data/imgs/personajes/p4/p4_disp1_arr.png");
static constexpr char *RUTA_PERSONAJE_4_ARR_DISP2 = (char *) ("../data/imgs/personajes/p4/p4_disp2_arr.png");
static constexpr char *RUTA_PERSONAJE_4_ARR_DANIADO = (char *) ("../data/imgs/personajes/p4/p4_damaged_arr.png");
static constexpr char *RUTA_PERSONAJE_4_ABA_CLARO = (char *) ("../data/imgs/personajes/p4/p4_l_aba.png");
static constexpr char *RUTA_PERSONAJE_4_ABA_NORMAL = (char *) ("../data/imgs/personajes/p4/p4_ll_aba.png");
static constexpr char *RUTA_PERSONAJE_4_ABA_OSCURO = (char *) ("../data/imgs/personajes/p4/p4_ll_aba.png");
static constexpr char *RUTA_PERSONAJE_4_ABA_DISP1 = (char *) ("../data/imgs/personajes/p4/p4_disp1_aba.png");
static constexpr char *RUTA_PERSONAJE_4_ABA_DISP2 = (char *) ("../data/imgs/personajes/p4/p4_disp2_aba.png");
static constexpr char *RUTA_PERSONAJE_4_ABA_DANIADO = (char *) ("../data/imgs/personajes/p4/p4_damaged_aba.png");
static constexpr char *RUTA_PERSONAJE_4_ESCUDO = (char *) ("../data/imgs/personajes/p4/p4_escudo.png");

static constexpr char *RUTA_PERSONAJE_DESCONECTADO = (char *) ("../data/imgs/personajes/p_desconectado.png");
static constexpr char *RUTA_PERSONAJE_DESCONECTADO_DANIADO = (char *) ("../data/imgs/personajes/p_desconectado_dmg.png");
static constexpr char *RUTA_PERSONAJE_DESCONECTADO_ESCUDO = (char *) ("../data/imgs/personajes/p_desconectado_escudo.png");

static constexpr char *RUTA_UI_PERSONAJE_1_VIVO = (char *) ("../data/imgs/ui/Character1_r.png");
static constexpr char *RUTA_UI_PERSONAJE_1_DISPARANDO = (char *) ("../data/imgs/ui/Character1_rl.png");
static constexpr char *RUTA_UI_PERSONAJE_1_DISPARANDO_2 = (char *) ("../data/imgs/ui/Character1_rl2.png");
static constexpr char *RUTA_UI_PERSONAJE_1_MUERTO = (char *) ("../data/imgs/ui/Character1_rm.png");
static constexpr char *RUTA_UI_PERSONAJE_1_GAME_OVER = (char *) ("../data/imgs/ui/Character1_go.png");
static constexpr char *RUTA_UI_PERSONAJE_1_DESCONECTADO = (char *) ("../data/imgs/ui/Character1_rd.png");
static constexpr char *RUTA_UI_PERSONAJE_2_VIVO = (char *) ("../data/imgs/ui/Character2_r.png");
static constexpr char *RUTA_UI_PERSONAJE_2_DISPARANDO = (char *) ("../data/imgs/ui/Character2_rl.png");
static constexpr char *RUTA_UI_PERSONAJE_2_DISPARANDO_2 = (char *) ("../data/imgs/ui/Character2_rl2.png");
static constexpr char *RUTA_UI_PERSONAJE_2_MUERTO = (char *) ("../data/imgs/ui/Character2_rm.png");
static constexpr char *RUTA_UI_PERSONAJE_2_DESCONECTADO = (char *) ("../data/imgs/ui/Character2_rd.png");
static constexpr char *RUTA_UI_PERSONAJE_2_GAME_OVER = (char *) ("../data/imgs/ui/Character2_go.png");
static constexpr char *RUTA_UI_PERSONAJE_3_VIVO = (char *) ("../data/imgs/ui/Character3_r.png");
static constexpr char *RUTA_UI_PERSONAJE_3_DISPARANDO = (char *) ("../data/imgs/ui/Character3_rl.png");
static constexpr char *RUTA_UI_PERSONAJE_3_DISPARANDO_2 = (char *) ("../data/imgs/ui/Character3_rl2.png");
static constexpr char *RUTA_UI_PERSONAJE_3_MUERTO = (char *) ("../data/imgs/ui/Character3_rm.png");
static constexpr char *RUTA_UI_PERSONAJE_3_DESCONECTADO = (char *) ("../data/imgs/ui/Character3_rd.png");
static constexpr char *RUTA_UI_PERSONAJE_3_GAME_OVER = (char *) ("../data/imgs/ui/Character3_go.png");
static constexpr char *RUTA_UI_PERSONAJE_4_VIVO = (char *) ("../data/imgs/ui/Character4_r.png");
static constexpr char *RUTA_UI_PERSONAJE_4_DISPARANDO = (char *) ("../data/imgs/ui/Character4_rl.png");
static constexpr char *RUTA_UI_PERSONAJE_4_DISPARANDO_2 = (char *) ("../data/imgs/ui/Character4_rl2.png");
static constexpr char *RUTA_UI_PERSONAJE_4_MUERTO = (char *) ("../data/imgs/ui/Character4_rm.png");
static constexpr char *RUTA_UI_PERSONAJE_4_DESCONECTADO = (char *) ("../data/imgs/ui/Character4_rd.png");
static constexpr char *RUTA_UI_PERSONAJE_4_GAME_OVER = (char *) ("../data/imgs/ui/Character4_go.png");


static constexpr char *RUTA_UI_PERSONAJE_1_BV = (char *) ("../data/imgs/ui/Vida_p1.png");
static constexpr char *RUTA_UI_PERSONAJE_2_BV = (char *) ("../data/imgs/ui/Vida_p2.png");
static constexpr char *RUTA_UI_PERSONAJE_3_BV = (char *) ("../data/imgs/ui/Vida_p3.png");
static constexpr char *RUTA_UI_PERSONAJE_4_BV = (char *) ("../data/imgs/ui/Vida_p4.png");
static constexpr char *RUTA_UI_PERSONAJE_TEST_BV = (char *) ("../data/imgs/ui/Vida_test.png");

static const std::string UI_CLAVE_PUNTAJE = "Puntaje";
static const std::string UI_CLAVE_VIDAS = "Vidas";
static const std::string UI_CLAVE_ENERGIA_PERSONAJE = "Energia_personaje";
static const float CONST_CONVERTIR_BARRA = 0.8f;

static const int ANCHO_BARRA_VIDA=80;
static const int ALTO_BARRA_VIDA=10;

static const int POS_VISTA_PERSONAJE_CLARO=0;
static const int POS_VISTA_PERSONAJE_NORMAL=1;
static const int POS_VISTA_PERSONAJE_OSCURO=2;
static const int POS_VISTA_PERSONAJE_DISP1=3;
static const int POS_VISTA_PERSONAJE_DISP2=4;
static const int POS_VISTA_PERSONAJE_DANIADO=5;

static const int CONST_BRILLOS_1=14;
static const int CONST_BRILLOS_2=5;

static const int POS_BRILLOS_3=3;

static const int LIMITE_DISP=10;
static const int LIMITE_DISP_MEDIO=5;

static const int NRO_PERSONAJE_ROJO = 0;
static const int NRO_PERSONAJE_VERDE = 1;
static const int NRO_PERSONAJE_AMARILLO = 2;
static const int NRO_PERSONAJE_AZUL = 3;
static const int NRO_PERSONAJE_DESCONECTADO = 4;

static std::vector<int> BRILLOS={POS_VISTA_PERSONAJE_CLARO, POS_VISTA_PERSONAJE_NORMAL, POS_VISTA_PERSONAJE_OSCURO, POS_VISTA_PERSONAJE_DISP1, POS_VISTA_PERSONAJE_DISP2};

static constexpr int MAX_CONTADOR_ESCUDO=120;
static constexpr int CORRECCION_X_ESCUDO=-15;
static constexpr int CORRECCION_Y_ESCUDO=-20;

static constexpr int CONST_CORREGIR_POS_ESCUDO_1=6;
static constexpr int CONST_CORREGIR_POS_ESCUDO_2=10;

static constexpr int MAX_VALOR_CONTADOR_BRILLO=15;

static constexpr size_t POS_BARRA_VIDA_TEST = 4;


#endif //CLIENTE_CONSTANTESPERSONAJE_H
