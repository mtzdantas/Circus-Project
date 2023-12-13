// Universidade Federal do Rio Grande do Norte
// Disciplina DCT1106 -- Programacão
// Projeto Sistema de Gestão de um Circo
// Developed by Mateus Dantas de Oliveira

// PARA ACESSAR O MÓDULO DE ADMINISTRAÇÃO:
// LOGIN: circo E SENHA: circo123

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ingressos.h"
#include "profissional.h"
#include "prof_eventos.h"
#include "verifica.h"

void sobre(void);

int main(){
    int option;
    int stop = 1;
    while (stop == 1){
        ordenar();
        system("clear||cls");
        printf("===============================\n        ~ GRAN C-IRCO ~\n    O VERDADEIRO ESPETACULO\n===============================\n");
        printf("[1]Atracoes\n"); printf("[2]Ingressos\n"); printf("[3]Buscar Reserva\n");
        printf("[4]Sobre Nos\n"); printf("[5]Administracao\n"); printf("[6]Sair\n");
        printf("DIGITE A OPCAO DESEJADA: ");
        scanf("%d", &option);
        fflush(stdin);
        switch (option){
            case 1:
                eventos_listar();
                break;
            case 2:
                intro_ingressos();
                break;
            case 3:
                ingressos_comprados();
                break;
            case 4:
                sobre();
                getchar();
                fflush(stdin);
                break;
            case 5:
                if (verificar_profissional() == 1) {
                    intro_profissional();
                }
                break;
            case 6:
                printf("VOLTE SEMPRE!");
                stop = 0;
                return 0;
            default:
                opcao_invalida();
                break;
        }
    }
    return 0;
}

void sobre(void){
    system("clear||cls");
    printf("===============================\n        ~ GRAN C-IRCO ~\n           SOBRE NOS\n===============================\n");
    printf("Bem-vindos ao nosso magico mundo de diversao e maravilhas!\n");
    printf("Aqui, no nosso amado circo, estamos prontos para transportar\n");
    printf("voce para um universo de encanto, risos e espetaculos incriveis.\n");
    printf("Permita-nos apresentar o 'GRAN C-IRCO' um lugar onde os sonhos\n");
    printf("ganham vida sob a grande lona e onde a imaginacao nao tem limites.\n");
    printf("\nO projeto foi desenvolvido com o intuito de melhorar a gestao\n");
    printf("de eventos e ingressos de um circo, trazendo praticidade para\n");
    printf("clientes e funcionarios.\n");
    printf("~ Developed By Mateus Dantas de Oliveira.\n");
    printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
    return;
}
