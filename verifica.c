#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "verifica.h"
#include "prof_eventos.h"
#include <ctype.h>

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
            printf("\nAPENAS NUMEROS POR FAVOR!\n");
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

// REFERÊNCIA DA FUNÇÃO DE VALIDAR DATA A SEGUIR:
// https://chat.openai.com/share/f6678427-2578-4f74-8ff0-ceeebff0ff73
// PS: FOI FEITA ALGUMAS ALTERAÇÕES.

bool validaData(int dia, int mes, int ano) {
    if (ano < 1000 || ano > 9999 || mes < 1 || mes > 12) {
        printf("\nDATA INVALIDA, TENTE NOVAMENTE.\n");
        return false;
    }

    int diasNoMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if ((ano % 400 == 0) || (ano % 100 != 0 && ano % 4 == 0)) {
        diasNoMes[2] = 29;
    }

    if (dia < 1 || dia > diasNoMes[mes]) {
        printf("\nDATA INVALIDA, TENTE NOVAMENTE.\n");
        return false;
    }

    return true;
}

bool validaCod(int codigo) {
    if(codigo >= 100 && codigo <= 999){
        FILE *ev; 
        ev = fopen("eventos.dat", "r+b");
        if (ev == NULL) {
            return true;
        }
        Eventos lido;
        while (fread(&lido, sizeof(Eventos), 1, ev) == 1) {
            if (lido.showcod == codigo) {
                return false;
                fclose(ev);
            }
        }
        fclose(ev);
    } else {
        return false;
    }
    return true;
}

bool validaLocal(char local[]) {
    local[strcspn(local, "\n")] = '\0';
    if (strlen(local) > 20) {
        return true;
    } else {
        printf("\nADICIONE MAIS INFORMACOES.\n");
        return false;
    }
}

// REFERÊNCIA DA FUNÇÃO DE VALIDAR HORÁRIO A SEGUIR:
// CHAT GPT
// PS: FOI FEITA ALGUMAS ALTERAÇÕES.

bool validaHorario(const char *horario) {
    char horarioCopia[6];
    strcpy(horarioCopia, horario);
    if (strlen(horarioCopia) != 5) {
        printf("\nERRO ENCONTRADO, DIGITE NOVAMENTE.");
        return false;
    }
    int horas = atoi(strtok(horarioCopia, ":"));
    if (horas < 0 || horas > 23) {
        printf("\nERRO ENCONTRADO, DIGITE NOVAMENTE.");
        return false;
    }
    int minutos = atoi(strtok(NULL, ":"));
    if (minutos < 0 || minutos > 59) {
        printf("\nERRO ENCONTRADO, DIGITE NOVAMENTE.");
        return false;
    }
    return true;
}

bool validaNumeros(char input[]) {
    input[strcspn(input, "\n")] = '\0';
    int i = 0;
    while (input[i] != '\0') {
        if (!isdigit(input[i])) {
            printf("\nERRO ENCONTRADO, DIGITE NOVAMENTE.");
            return false;
        }
        i++;
    }
    return true;
}

bool validaIngresso(int codIng) {
    if (codIng >= 100 && codIng <= 999) {    
        return true;
    }
    return false;
}