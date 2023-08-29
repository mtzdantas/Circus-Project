// Universidade Federal do Rio Grande do Norte
// Disciplina DCT1106 -- Programa??o
// Projeto Sistema de Gest?o de um Circo
// Developed by Mateus Dantas de Oliveira

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void intro_ingressos(void);

void verificar_profissional(void);
void intro_profissional(void);
void profissional_eventos(void);
void profissional_relatorios(void);

void sobre(void);
void desenvolvedor(void);

// VARI�VEIS DE LOGIN
char login[6] = {"circo"};
char senha[9] = {"circo123"};
char trylogin[11];
char trysenha[11];

// VARI�VEIS DE MENUS
int option;
int stop = 1;

int main(void){
    setlocale(LC_ALL, "Portuguese_Brazil");
    while (stop == 1){
        system("clear||cls");
        printf("[1]Atra��es\n"); printf("[2]Ingressos\n"); printf("[3]Sobre N�s\n");
        printf("[4]Desenvolvedor\n"); printf("[5]Administra��o\n"); printf("[6]Sair\n");
        printf("DIGITE A OP��O DESEJADA: ");
        scanf("%d", &option);
        fflush(stdin);
        switch (option){
            case 1:
                system("clear||cls");
                printf("ATRA��ES CADASTRADAS.\n");
                printf("- \n- PRESSIONE ENTER PARA CONTINUAR. -");
                getchar();
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
                verificar_profissional();
                break;
            case 6:
                printf("VOLTE SEMPRE!");
                stop = 0;
                break;
            default:
                system("clear||cls");
                printf("POR FAVOR, SELECIONE UMA OP��O V�LIDA.\n");
                printf("- \n- PRESSIONE ENTER PARA CONTINUAR. -");
                getchar();
                system("clear||cls");
                break;
        }
    }
    return 0;
}

void intro_ingressos(void){
    stop = 0;
    while (stop == 0){
        system("clear||cls");
        printf("[1]Comprar\n"); printf("[2]Cancelar\n"); printf("[3]Meu Carrinho\n");
        printf("[4]Finalizar\n"); printf("[5]Compras Realizadas\n"); printf("[6]Voltar\n");
        printf("DIGITE A OP��O DESEJADA: ");
        scanf("%d", &option);
        fflush(stdin);
        switch (option){
            case 1:
                system("clear||cls");
                printf("COMPRAR\n"); // Aqui ter� que informar o c�digo do show que ser� consultado ao clicar enter.
                printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
                getchar();
                break;
            case 2:
                system("clear||cls");
                printf("CANCELAR COMPRAS\n"); // Aqui ter� que informar o c�digo do show que ser� consultado ao clicar enter.
                printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
                getchar();
                break;
            case 3:
                system("clear||cls");
                printf("MEU CARRINHO\n"); // Aqui listar� o que o cliente comprou at� agora.
                printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
                getchar();
                break;
            case 4:
                system("clear||cls");
                printf("FINALIZAR COMPRA\n"); // Aqui vai gerar um c�digo para pagar e ao ser pago a compra � aprovada,
                printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
                getchar(); // diminuindo a quantidade de vagas e cadastrando nas vendas daquele evento. Pedir n�mero/CPF/nome.
                break;
            case 5:
                system("clear||cls");
                printf("COMPRAS REALIZADAS\n"); // Aqui mostrar� ingressos comprados quando for informado nome completo/CPF.
                printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
                getchar();
                break;
            case 6:
                // Aqui apaga o carrinho do cliente e volta para tela inicial.
                stop = 1;
                break; 
            default:
                printf("POR FAVOR, SELECIONE UMA OP��O V�LIDA.\n");
                printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
                getchar();
                break;
        }
    }
}

void verificar_profissional(void){
    int checklog = 1;
    int checksen = 1;
    int cancel = 1;
    while (checklog != 0 || checksen != 0){
        system("clear||cls");
        printf("INFORME O LOGIN:\n");
        gets(trylogin);
        fflush(stdin);
        printf("INFORME A SENHA:\n");
        gets(trysenha);
        fflush(stdin);
        checklog = strcmp(login, trylogin);
        checksen = strcmp(senha, trysenha);
        if (checklog == 0 && checksen == 0) {
            printf("LOGIN REALIZADO COM SUCESSO.\n");
            printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
            getchar();
            intro_profissional();
        }
        else {
            printf("LOGIN OU SENHA INCORRETOS.\n");
            printf("DIGITE '1' PARA CONTINUAR E '2' PARA SAIR.\n");
            scanf("%d", &cancel);
            fflush(stdin);
            if (cancel == 2){
                break;
            }
        }
    }        
}

void intro_profissional(void){
    stop = 0;
    while (stop == 0){
        system("clear||cls");
        printf("[1]eventos\n"); // Usar no cadastro a localiza��o, hor�rio, data, pre�o
        printf("[2]Relat�rios\n"); // vagas disponibilizadas e c�digo de show (para acessar informa��es facilmente).
        printf("[3]Voltar\n");
        printf("DIGITE A OP��O DESEJADA: ");
        scanf("%d", &option);
        fflush(stdin);
        switch (option){
            case 1:
                profissional_eventos();
                break;
            case 2:
                profissional_relatorios();
                break;
            case 3:
                stop = 1;
                break;
            default:
                printf("POR FAVOR, SELECIONE UMA OP��O V�LIDA.\n");
                printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
                getchar();
                break;
        }
    }    
}            

void profissional_eventos(void){
    stop = 1;
    while (stop == 1){
        system("clear||cls");
        printf("[1]Listar\n"); printf("[2]Cadastrar\n"); printf("[3]Cancelar\n");
        printf("[4]Alterar\n"); printf("[5]Voltar\n");
        printf("DIGITE A OP��O DESEJADA: ");
        scanf("%d", &option);
        fflush(stdin);
        switch (option){
            case 1:
                system("clear||cls");
                printf("LISTA DE eventos.\n");
                printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
                getchar();
                break;
            case 2:
                system("clear||cls");
                printf("CADASTRAR eventos\n");
                printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
                getchar();
                // Usar no cadastro a localiza��o, hor�rio, data, pre�o, vagas disponibilizadas e c�digo de show.
                break;
            case 3:
                system("clear||cls");
                printf("CANCELAR EVENTO.\n");
                printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
                getchar();
                break;
            case 4:
                system("clear||cls");
                printf("ALTERAR DADOS DE EVENTO.\n");
                printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
                getchar();
                break;
            case 5:
                stop = 0;
                break;
            default:
                printf("POR FAVOR, SELECIONE UMA OP��O V�LIDA.\n");
                printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
                getchar();
                break;
        }
    }
}

void profissional_relatorios(void){
    system("clear||cls");
    printf("GERANDO RELAT�RIOS...\n"); // Informa��es de quantas vendas foram feitas, e quanto foi arrecatado.
    printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
                getchar();
}

void desenvolvedor(void){
    system("clear||cls");
    printf("~ DESENVOLVEDOR \n"); printf("===================\n\n");
    printf("O projeto foi desenvolvido com o intuito de melhorar a gest�o\n");
    printf("de eventos e ingressos de um circo, trazendo praticidade para\n");
    printf("clientes e funcion�rios.\n");
    printf("~ Developed By Mateus Dantas de Oliveira.\n");
    printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
    getchar();
}

void sobre(void){
    system("clear||cls");
    printf("~ SOBRE N�S \n"); printf("===============\n\n");
    printf("Bem-vindos ao nosso m�gico mundo de divers�o e maravilhas!\n");
    printf("Aqui, no nosso amado circo, estamos prontos para transportar\n");
    printf("voc� para um universo de encanto, risos e espet�culos incr�veis.\n");
    printf("Permita-nos apresentar o 'GRAN C-IRCO' - um lugar onde os sonhos\n");
    printf("ganham vida sob a grande lona e onde a imagina��o n�o tem limites.\n");
    printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
    getchar();
}
