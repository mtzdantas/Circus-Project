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
#include "util.h"
#include "prof_eventos.h"

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
                return 0;
            default:
                opcao_invalida();
                break;
        }
    }
    return 0;
}
