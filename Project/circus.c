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

// VARIÁVEIS DE LOGIN
char login[6] = {"circo"};
char senha[9] = {"circo123"};
char trylogin[11];
char trysenha[11];

// VARIÁVEIS DE MENUS
int option;
int stop = 1;

int main(void){
    setlocale(LC_ALL, "Portuguese_Brazil");
    while (stop == 1){
        system("clear||cls");
        printf("[1]Atrações\n"); printf("[2]Ingressos\n"); printf("[3]Sobre Nós\n");
        printf("[4]Desenvolvedor\n"); printf("[5]Administração\n"); printf("[6]Sair\n");
        printf("DIGITE A OPÇÃO DESEJADA: ");
        scanf("%d", &option);
        fflush(stdin);
        switch (option){
            case 1:
                system("clear||cls");
                printf("ATRAÇÕES CADASTRADAS.\n");
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
                printf("POR FAVOR, SELECIONE UMA OPÇÃO VÁLIDA.\n");
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
        printf("DIGITE A OPÇÃO DESEJADA: ");
        scanf("%d", &option);
        fflush(stdin);
        switch (option){
            case 1:
                system("clear||cls");
                printf("COMPRAR\n"); // Aqui terá que informar o código do show que será consultado ao clicar enter.
                printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
                getchar();
                break;
            case 2:
                system("clear||cls");
                printf("CANCELAR COMPRAS\n"); // Aqui terá que informar o código do show que será consultado ao clicar enter.
                printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
                getchar();
                break;
            case 3:
                system("clear||cls");
                printf("MEU CARRINHO\n"); // Aqui listará o que o cliente comprou até agora.
                printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
                getchar();
                break;
            case 4:
                system("clear||cls");
                printf("FINALIZAR COMPRA\n"); // Aqui vai gerar um código para pagar e ao ser pago a compra é aprovada,
                printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
                getchar(); // diminuindo a quantidade de vagas e cadastrando nas vendas daquele evento. Pedir número/CPF/nome.
                break;
            case 5:
                system("clear||cls");
                printf("COMPRAS REALIZADAS\n"); // Aqui mostrará ingressos comprados quando for informado nome completo/CPF.
                printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
                getchar();
                break;
            case 6:
                // Aqui apaga o carrinho do cliente e volta para tela inicial.
                stop = 1;
                break; 
            default:
                printf("POR FAVOR, SELECIONE UMA OPÇÃO VÁLIDA.\n");
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
        printf("[1]eventos\n"); // Usar no cadastro a localização, horário, data, preço
        printf("[2]Relatórios\n"); // vagas disponibilizadas e código de show (para acessar informações facilmente).
        printf("[3]Voltar\n");
        printf("DIGITE A OPÇÃO DESEJADA: ");
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
                printf("POR FAVOR, SELECIONE UMA OPÇÃO VÁLIDA.\n");
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
        printf("DIGITE A OPÇÃO DESEJADA: ");
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
                // Usar no cadastro a localização, horário, data, preço, vagas disponibilizadas e código de show.
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
                printf("POR FAVOR, SELECIONE UMA OPÇÃO VÁLIDA.\n");
                printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
                getchar();
                break;
        }
    }
}

void profissional_relatorios(void){
    system("clear||cls");
    printf("GERANDO RELATÓRIOS...\n"); // Informações de quantas vendas foram feitas, e quanto foi arrecatado.
    printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
                getchar();
}

void desenvolvedor(void){
    system("clear||cls");
    printf("~ DESENVOLVEDOR \n"); printf("===================\n\n");
    printf("O projeto foi desenvolvido com o intuito de melhorar a gestão\n");
    printf("de eventos e ingressos de um circo, trazendo praticidade para\n");
    printf("clientes e funcionários.\n");
    printf("~ Developed By Mateus Dantas de Oliveira.\n");
    printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
    getchar();
}

void sobre(void){
    system("clear||cls");
    printf("~ SOBRE NÓS \n"); printf("===============\n\n");
    printf("Bem-vindos ao nosso mágico mundo de diversão e maravilhas!\n");
    printf("Aqui, no nosso amado circo, estamos prontos para transportar\n");
    printf("você para um universo de encanto, risos e espetáculos incríveis.\n");
    printf("Permita-nos apresentar o 'GRAN C-IRCO' - um lugar onde os sonhos\n");
    printf("ganham vida sob a grande lona e onde a imaginação não tem limites.\n");
    printf("\n- PRESSIONE ENTER PARA CONTINUAR.");
    getchar();
}
