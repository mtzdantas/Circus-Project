// Universidade Federal do Rio Grande do Norte
// Disciplina DCT1106 -- Programação
// Projeto Sistema de Gestão de um Circo
// Developed by Mateus Dantas de Oliveira

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "ingressos.h"
#include "profissional.h"

void intro_profissional(void);
void sobre(void);
void desenvolvedor(void);

int main(){
    int option;
    int stop = 1;
    setlocale(LC_CTYPE , "" );
    while (stop == 1){
        system("clear||cls");
        wprintf(L"===============================\n        ~ GRAN C-IRCO ~\n    O VERDADEIRO ESPETÁCULO\n===============================\n");
        wprintf(L"[1]Atrações\n"); wprintf(L"[2]Ingressos\n"); wprintf(L"[3]Sobre Nós\n");
        wprintf(L"[4]Desenvolvedor\n"); wprintf(L"[5]Administração\n"); wprintf(L"[6]Sair\n");
        wprintf(L"DIGITE A OPÇÃO DESEJADA: ");
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
                sobre();
                break;
            case 4:
                desenvolvedor();
                break;
            case 5:
                if (verificar_profissional() == 1) {
                    intro_profissional();
                }
                break;
            case 6:
                wprintf(L"VOLTE SEMPRE!");
                stop = 0;
                break;
            default:
                opcao_invalida();
                break;
        }
    }
    return 0;
}

void desenvolvedor(void){
    system("clear||cls");
    wprintf(L"===============================\n        ~ GRAN C-IRCO ~\n         DESENVOLVEDOR\n===============================\n");
    wprintf(L"O projeto foi desenvolvido com o intuito de melhorar a gestão\n");
    wprintf(L"de eventos e ingressos de um circo, trazendo praticidade para\n");
    wprintf(L"clientes e funcionários.\n");
    wprintf(L"~ Developed By Mateus Dantas de Oliveira.\n");
    wprintf(L"\n- PRESSIONE ENTER PARA CONTINUAR.");
    getchar();
    fflush(stdin);
}

void sobre(void){
    system("clear||cls");
    wprintf(L"===============================\n        ~ GRAN C-IRCO ~\n           SOBRE NÓS\n===============================\n");
    wprintf(L"Bem-vindos ao nosso mágico mundo de diversão e maravilhas!\n");
    wprintf(L"Aqui, no nosso amado circo, estamos prontos para transportar\n");
    wprintf(L"você para um universo de encanto, risos e espetáculos incríveis.\n");
    wprintf(L"Permita-nos apresentar o 'GRAN C-IRCO' - um lugar onde os sonhos\n");
    wprintf(L"ganham vida sob a grande lona e onde a imaginação não tem limites.\n");
    wprintf(L"\n- PRESSIONE ENTER PARA CONTINUAR.");
    getchar();
    fflush(stdin);
}