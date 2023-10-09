#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// REFERÊNCIA DA FUNÇÃO DE VALIDAR CPF A SEGUIR:
// https://github.com/Mumber162/StyleC-Hair/blob/main/util.c
// PS: FOI FEITA PEQUENAS ALTERAÇÕES NAS SAÍDAS DE TEXTO.

int validaCPF(char *cpf)
{
    // se tem 11 dígitos
    if (strlen(cpf) != 11) {
        printf("\nPRECISA CONTER 11 DIGITOS!\n");
        printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
        getchar();
        return 0;
    }

    // se todos os caracteres são dígitos
    for (int i = 0; i < 11; i++) {
        if (cpf[i] < '0' || cpf[i] > '9') {
            printf("\nAPENAS NÚMEROS POR FAVOR!\n");
            printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
            getchar();
            return 0;
        }
    }

    // Calcula o primeiro dígito verificador
    int soma = 0;
    for (int i = 0; i < 9; i++) {
        soma += (cpf[i] - '0') * (10 - i);
    }
    int firstDigit = 11 - (soma % 11);

    // se primeiro dígito é válido
    if (firstDigit >= 10) {
        firstDigit = 0;
    }
    if (cpf[9] - '0' != firstDigit) {
        printf("DIGITE O CPF CORRETAMENTE.");
        printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
        getchar();
        return 0;
    }

    // egundo dígito
    soma = 0;
    for (int i = 0; i < 10; i++) {
        soma += (cpf[i] - '0') * (11 - i);
    }
    int secndDigit = 11 - (soma % 11);

    // se segundo dígito é válido
    if (secndDigit >= 10) {
        secndDigit = 0;
    }
    if (cpf[10] - '0' != secndDigit) {
        printf("DIGITE O CPF CORRETAMENTE.");
        printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
        getchar();
        return 0;
    }

    // até aqui, o CPF é válido
    return 1;
}