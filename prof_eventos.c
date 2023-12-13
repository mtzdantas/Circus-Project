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
    ordenar();
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
    int t = 0;
    printf("SHOW || CODIGO || DATA       || LOCAL                                                        || HORARIO || PRECO || VAGAS\n");
    printf("==== || ====== || ========== || ============================================================ || ======= || ===== || =====\n");
    while (fread(&cod2, sizeof(Eventos), 1, ev) == 1) {
        if (cod2.status != 'x') {
            t++;
            printf(" %02d  ||  %d   || %02d/%02d/%4d || %-60s ||  %s  || R$ %d || %d\n", t, cod2.showcod, cod2.dia, cod2.mes, cod2.ano, cod2.local, cod2.horario, cod2.preco, cod2.vagas);
        }
    }
    printf("=========================================================================================================================");
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
    cod2.vendas = 0;
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
    Eventos cod2;
    do {
        printf("NOVA DATA DO EVENTO (DD/MM/AAAA):\n");
        scanf("%d/%d/%d", &dia, &mes, &ano);
        fflush(stdin);
    } while (!validaData(dia, mes, ano));
    cod2.dia = dia; cod2.mes = mes; cod2.ano = ano;
    do {
        printf("NOVA LOCALIZACAO:\n");
        fgets(local, sizeof(local), stdin);
        fflush(stdin);
    } while (!validaLocal(local));
    local[strcspn(local, "\n")] = '\0';
    strncpy(cod2.local, local, 61);
    do {
        printf("NOVO HORARIO (HH:MM):\n");
        fgets(horario, sizeof(horario), stdin);
        fflush(stdin);
    } while (!validaHorario(horario));
    horario[strcspn(horario, "\n")] = '\0';
    strncpy(cod2.horario, horario, 6);
    do {
        printf("NOVO PRECO DO INGRESSO:\n");
        fgets(preco, sizeof(preco), stdin);
        fflush(stdin);
    } while (!validaNumeros(preco));
    cod2.preco = atoi(preco);
    do {
        printf("NOVAS VAGAS DISPONIBILIZADAS:\n");
        fgets(vagas, sizeof(vagas), stdin);
        fflush(stdin);
    } while (!validaNumeros(vagas));
    cod2.vagas = atoi(vagas);
    atualizarEvento(list, cod2.dia, cod2.mes, cod2.ano, cod2.local, cod2.horario, cod2.preco, cod2.vagas);
    printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
    getchar();
    fflush(stdin);
    return;
}

/*FUNÇÕES ABAIXO FEITAS PELO CHAT GPT*/

void atualizarEvento(int codigo, int novoDia, int novoMes, int novoAno, const char novoLocal[61], const char novoHorario[6], int novoPreco, int novaVagas) {
    FILE *arquivo;
    FILE *temporario;

    arquivo = fopen("eventos.dat", "rb");
    temporario = fopen("temp.dat", "wb");

    if (arquivo == NULL || temporario == NULL) {
        printf("ERRO AO ABRIR OS ARQUIVOS.\n");
        exit(1);
    }

    Eventos evento;

    while (fread(&evento, sizeof(Eventos), 1, arquivo) == 1) {
        if (evento.showcod == codigo) {
            evento.dia = novoDia;
            evento.mes = novoMes;
            evento.ano = novoAno;
            strcpy(evento.local, novoLocal);
            strcpy(evento.horario, novoHorario);
            evento.preco = novoPreco;
            evento.vagas = novaVagas;
        }
        fwrite(&evento, sizeof(Eventos), 1, temporario);
    }

    fclose(arquivo);
    fclose(temporario);

    remove("eventos.dat");
    rename("temp.dat", "eventos.dat");
}

int compararPorData(const void *a, const void *b) {
    const Eventos *eventoA = (const Eventos *)a;
    const Eventos *eventoB = (const Eventos *)b;

    // Comparar anos
    if (eventoA->ano != eventoB->ano) {
        return eventoA->ano - eventoB->ano;
    }

    // Comparar meses
    if (eventoA->mes != eventoB->mes) {
        return eventoA->mes - eventoB->mes;
    }

    // Comparar dias
    return eventoA->dia - eventoB->dia;
}

int ordenar(void) {
    // Abrir o arquivo para leitura e escrita
    FILE *arquivo = fopen("eventos.dat", "r+b");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    // Contar o número de eventos no arquivo
    fseek(arquivo, 0, SEEK_END);
    long tamanhoArquivo = ftell(arquivo);
    rewind(arquivo);
    size_t numEventos = tamanhoArquivo / sizeof(Eventos);

    // Ler os eventos do arquivo para um array
    Eventos *eventos = (Eventos *)malloc(numEventos * sizeof(Eventos));
    fread(eventos, sizeof(Eventos), numEventos, arquivo);

    // Ordenar os eventos por data
    qsort(eventos, numEventos, sizeof(Eventos), compararPorData);

    // Reescrever os eventos ordenados de volta no arquivo
    fseek(arquivo, 0, SEEK_SET);
    fwrite(eventos, sizeof(Eventos), numEventos, arquivo);

    // Fechar o arquivo e liberar a memória alocada
    fclose(arquivo);
    free(eventos);

    return 0;
}