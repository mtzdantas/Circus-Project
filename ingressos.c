#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ingressos.h"
#include "verifica.h"
#include "prof_eventos.h"
int cod1 = 0, cod3, carrinho[20], x = 0;
char cpf[12], senha[21];

void intro_ingressos(void){
    int stop = 0;
    int option;
    while (stop == 0){
        system("clear||cls");
        printf("===============================\n        ~ GRAN C-IRCO ~\n           INGRESSOS\n===============================\n");
        printf("[1]Reservar\n"); printf("[2]Cancelar\n"); printf("[3]Meu Carrinho\n");
        printf("[4]Finalizar\n"); printf("[5]Voltar\n");
        printf("DIGITE A OPCAO DESEJADA: ");
        scanf("%d", &option);
        fflush(stdin);
        switch (option){
            case 1: 
                ingressos_comprar();
                break;
            case 2:
                ingressos_cancelar();
                break;
            case 3:
                ingressos_carrinho();
                break;
            case 4:
                ingressos_finalizar();
                break;
            case 5:
                ingressos_sair();
                stop = 1;
                break; 
            default:
                opcao_invalida();
                break;
        }
    }
    return;
}

void ingressos_comprar(void){
    system("clear||cls");
    do {
        if (cod1 == 1){
            eventos_listar();
            system("clear||cls");
        }
        printf("===============================\n        ~ GRAN C-IRCO ~\n            RESERVA\n===============================\n");
        printf("DIGITE O CODIGO DO ESPETACULO QUE VOCE DESEJA RESERVAR O INGRESSO:\n");
        printf("PARA CONSULTAR A LISTA DE ESPETACULOS, DIGITE '1'.\n");
        scanf("%d", &cod1);
        fflush(stdin);   
    } while (cod1 == 1);
    FILE *ev; 
    ev = fopen("eventos.dat", "rb");
    if (ev == NULL) {
        printf("ERRO AO ABRIR O ARQUIVO.\n");
    } else {
        cod3 = cod1;
        Eventos cod3;
        int a = 1;
        while(fread(&cod3, sizeof(Eventos), 1, ev)) {
            if (cod1 == cod3.showcod) {
                a++;
                carrinho[x] = cod1;
                x++;
                printf("ESPETACULO ADICIONADO AO CARRINHO!\n");  
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

void ingressos_cancelar(void){
    system("clear||cls");
    do {
        if (cod1 == 1){
            ingressos_carrinho();
            system("clear||cls");
        }
        printf("===============================\n        ~ GRAN C-IRCO ~\n            CANCELAR\n===============================\n");
        printf("DIGITE O CODIGO DO ESPETACULO QUE VOCE DESEJA CANCELAR O INGRESSO:\n");
        printf("PARA CONSULTAR O SEU CARRINHO, DIGITE '1'.\n");
        scanf("%d", &cod1);
        fflush(stdin);   
    } while (cod1 == 1);
    FILE *ev; 
    ev = fopen("eventos.dat", "rb");
    if (ev == NULL) {
        printf("ERRO AO ABRIR O ARQUIVO.\n");
    } else {
        cod3 = cod1;
        Eventos cod3;
        int a = 1;
        while(fread(&cod3, sizeof(Eventos), 1, ev)) {
            if (cod1 == cod3.showcod) {
                a++;
                for (int i = 0; i <= 20; i++) {
                    if (cod1 == carrinho[i]) {
                        carrinho[i] = 0;
                        printf("ESPETACULO CANCELADO DO CARRINHO!\n");  
                        break;
                    }
                }
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

void ingressos_carrinho(void){
    system("clear||cls");
    printf("===============================\n        ~ GRAN C-IRCO ~\n            CARRINHO\n===============================\n");
    FILE *ev; 
    ev = fopen("eventos.dat", "rb");
    if (ev == NULL) {
        printf("ERRO AO ABRIR O ARQUIVO.\n");
    } else {
        Eventos codcar;
        for (int i = 0; i <= 20; i++) {
            fseek(ev, 0, SEEK_SET);
            while (fread(&codcar, sizeof(Eventos), 1, ev) == 1) {
                if (codcar.showcod == carrinho[i]){
                    printf("EVENTO DE CODIGO: %d\nDATA: %d/%d/%d\nLOCAL: %s\nHORARIO: %s\nPRECO: R$%d REAIS\nVAGAS DISPONIVEIS: %d\n", codcar.showcod, codcar.dia, codcar.mes, codcar.ano, codcar.local, codcar.horario, codcar.preco, codcar.vagas);
                    printf("===============================\n");
                }
            }
        }
    }
    printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
    getchar();
    fflush(stdin);
    return;
}   

void ingressos_finalizar(void){
    int op;
    do {
        system("clear||cls");
        printf("===============================\n        ~ GRAN C-IRCO ~\n           FINALIZAR\n===============================\n");
        printf("INFORME SEU CPF (APENAS NUMEROS):\n");
        fgets(cpf, sizeof(cpf), stdin);
        fflush(stdin);
    } while (validaCPF(cpf) == 0);
    printf("INFORME SUA SENHA (ATE 20 CARACTERES)");
    fgets(senha, sizeof(senha), stdin);
    fflush(stdin);
    printf("CPF: %s", cpf);
    printf("\nSENHA: %s", senha);
    printf("\nDIGITE 1 PARA FINALIZAR A RESERVA OU OUTRA TECLA PRA SAIR.\n");
    scanf("%d", &op);
    fflush(stdin);
    if (op == 1){
        // Diminuir a quantidade de vagas e cadastrar no relatório de vendas daquele evento.
        Cliente cad;
        for (int i = 0; i <= 20; i++) {
            cad.compras[i] = carrinho[i];          
        }
        FILE *ev; 
        ev = fopen("clientes.dat", "ab");
        if (ev == NULL) {
            printf("ERRO AO ABRIR O ARQUIVO.\n");
        } else {
            fwrite(&cad, sizeof(Cliente), 1, ev);
            printf("CADASTRO REALIZADO COM SUCESSO!\n");
        }
        fclose(ev);
        printf("\nRESERVA FINALIZADA!\nOBS: PARA VALIDAR SEU INGRESSO, BASTA REALIZAR O PAGAMENTO NA HORA DO SHOW\n");
        printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
        getchar();
        fflush(stdin);
    }
    return;
}

void ingressos_comprados(void){
    do {
        system("clear||cls");
        printf("===============================\n        ~ GRAN C-IRCO ~\n      RESERVAS CONCLUIDAS\n===============================\n");
        printf("DIGITE SEU CPF:\n");
        fgets(cpf, 12, stdin);
        fflush(stdin);
    } while (validaCPF(cpf) == 0);
    // Fazer outra verificação se existe esse CPF cadastrado.
    printf("LISTA DE INGRESSOS RESERVADOS.\n");
    printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
    getchar();
    fflush(stdin);
    return;
}

void ingressos_sair(void){
    // Aqui apaga o carrinho do cliente e volta para tela inicial.
    return;
}

void opcao_invalida(void){
    system("clear||cls");
    printf("===============================\n        ~ GRAN C-IRCO ~\n        ERRO ENCONTRADO\n===============================\n");
    printf("POR FAVOR, SELECIONE UMA OPCAO VALIDA.\n");
    printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
    getchar();
    fflush(stdin);
    system("clear||cls");
    return;
}
