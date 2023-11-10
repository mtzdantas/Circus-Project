#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "prof_eventos.h"
#include "verifica.h"
#include "ingressos.h"

char local[61], horario[6], preco[4], vagas[5];
int cod2 = 0, cod, list = 0, dia, mes, ano;

void eventos_listar(void){
    system("clear||cls");
    printf("===============================\n        ~ GRAN C-IRCO ~\n          ESPETACULOS\n===============================\n");
    FILE *ev; 
    ev = fopen("eventos.dat", "rb");
    if (ev == NULL) {
        printf("NAO EXISTE EVENTOS CADASTRADOS.\n");
        printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
        getchar();
        fflush(stdin);
    } else {
    Eventos cod2;
    while (fread(&cod2, sizeof(Eventos), 1, ev) == 1) {
        if (cod2.status != 'x') {
            printf("EVENTO DE CODIGO: %d\nDATA: %d/%d/%d\nLOCAL: %s\nHORARIO: %s\nPRECO: R$%d REAIS\nVAGAS DISPONIVEIS: %d\n", cod2.showcod, cod2.dia, cod2.mes, cod2.ano, cod2.local, cod2.horario, cod2.preco, cod2.vagas);
            printf("===============================\n");  
        }
    }
    fclose(ev);
    printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
    getchar();
    fflush(stdin);
    return;
    }
}

void eventos_cadastrar(void){
    system("clear||cls");
    printf("===============================\n        ~ GRAN C-IRCO ~\n           CADASTRAR\n===============================\n");
    do {
        printf("CODIGO DE ESPETACULO (3 DIGITOS):\n");
        scanf("%d", &cod);
        fflush(stdin);
    } while (!validaCod(cod));
    cod2 = cod;
    Eventos cod2;
    cod2.status = 'v';
    cod2.showcod = cod;
    do {
        printf("DATA DO EVENTO (DD/MM/AAAA):\n");
        scanf("%d/%d/%d", &dia, &mes, &ano);
        fflush(stdin);
    } while (!validaData(dia, mes, ano));
    cod2.dia = dia; cod2.mes = mes; cod2.ano = ano;
    do {
        printf("LOCALIZACAO:\n");
        fgets(local, sizeof(local), stdin);
        fflush(stdin);
    } while (!validaLocal(local));
    local[strcspn(local, "\n")] = '\0';
    strncpy(cod2.local, local, 61);
    do {
        printf("HORARIO (HH:MM):\n");
        fgets(horario, sizeof(horario), stdin);
        fflush(stdin);
    } while (!validaHorario(horario));
    horario[strcspn(horario, "\n")] = '\0';
    strncpy(cod2.horario, horario, 6);
    do {
        printf("PRECO DO INGRESSO:\n");
        fgets(preco, sizeof(preco), stdin);
        fflush(stdin);
    } while (!validaNumeros(preco));
    cod2.preco = atoi(preco);
    do {
        printf("VAGAS DISPONIBILIZADAS:\n");
        fgets(vagas, sizeof(vagas), stdin);
        fflush(stdin);
    } while (!validaNumeros(vagas));
    cod2.vagas = atoi(vagas);
    FILE *ev; 
    ev = fopen("eventos.dat", "ab");
    if (ev == NULL) {
        printf("ERRO AO ABRIR O ARQUIVO.\n");
    } else {
        fwrite(&cod2, sizeof(Eventos), 1, ev);
        printf("CADASTRO REALIZADO COM SUCESSO!\n");
    }
    fclose(ev);
    printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
    getchar();
    fflush(stdin);
    return;
}

void eventos_cancelar(void){
    system("clear||cls");
    do {
        if (cod2 == 1){
            eventos_listar();
            system("clear||cls");
        }
        printf("===============================\n        ~ GRAN C-IRCO ~\n            CANCELAR\n===============================\n");
        printf("DIGITE O CODIGO DO ESPETACULO QUE VOCE DESEJA CANCELAR:\n");
        printf("PARA CONSULTAR A LISTA DE ESPETACULOS, DIGITE '1'.\n");
        scanf("%d", &cod2);
        fflush(stdin);
    } while (cod2 == 1);
    FILE *ev; 
    ev = fopen("eventos.dat", "r+b");
    if (ev == NULL) {
        printf("ERRO AO ABRIR O ARQUIVO.\n");
    } else {
        cod = cod2;
        Eventos cod2;
        off_t tamanho = sizeof(Eventos);
        int a = 1;
        while(fread(&cod2, sizeof(Eventos), 1, ev)) {
            if (cod == cod2.showcod) {
                a++;
                cod2.status = 'x';
                fseek(ev, -tamanho, SEEK_CUR);
                fwrite(&cod2, sizeof(Eventos), 1, ev);
                printf("ESPETACULO CANCELADO COM SUCESSO!\n");  
                break;
            };
        }
        if (a == 1) {
            printf("NAO TEM NENHUM ESPETACULO COM ESSE CODIGO.");
        }
        fclose(ev);
        }
    printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
    getchar();
    fflush(stdin);
    return;
}

void eventos_alterar(void){
    system("clear||cls");
    do {
        if (list == 1) {
            eventos_listar();
            system("clear||cls");
        }
        printf("===============================\n        ~ GRAN C-IRCO ~\n            ALTERAR\n===============================\n");
        printf("DIGITE O CODIGO DO EVENTO QUE DESEJA ALTERAR: \n");
        printf("PARA CONSULTAR A LISTA DE ESPETACULOS, DIGITE '1'.\n");
        scanf("%d", &list);
        fflush(stdin);
    } while (list == 1);
    system("clear||cls");
    printf("===============================\n        ~ GRAN C-IRCO ~\n            ALTERAR\n===============================\n");
    printf("NOVA DATA DO EVENTO:\n");
    scanf("%d/%d/%d", &dia, &mes, &ano);
    fflush(stdin);
    printf("DATA DO EVENTO ALTERADA.\n");
    printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
    getchar();
    fflush(stdin);
    printf("NOVA LOCALIZACAO:\n");
    fgets(local, sizeof(local), stdin);
    fflush(stdin);
    printf("LOCALIZACAO ALTERADA.\n");
    printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
    getchar();
    fflush(stdin);
    printf("NOVO HORARIO:\n");
    fgets(horario, sizeof(horario), stdin);
    fflush(stdin);
    printf("HORARIO ALTERADO.\n");
    printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
    getchar();
    fflush(stdin);
    printf("NOVO PRECO DO INGRESSO:\n");
    fgets(preco, sizeof(preco), stdin);
    fflush(stdin);
    printf("PRECO DO INGRESSO ALTERADO.\n");
    printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
    getchar();
    fflush(stdin);
    printf("NOVA QUANTIDADE DE VAGAS:\n");
    fgets(vagas, sizeof(vagas), stdin);
    fflush(stdin);
    printf("QUANTIDADE DE VAGAS ALTERADA.\n");
    printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
    getchar();
    fflush(stdin);
    printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
    getchar();
    fflush(stdin);
    return;
}
