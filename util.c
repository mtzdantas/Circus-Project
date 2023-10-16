// REFERÊNCIA DA FUNÇÃO DE LIMPAR TELA:
// https://github.com/FlaviusGorgonio/LinguaSolta_2021/blob/main/util.c
#include <stdlib.h>
void limpaTela(void) {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}