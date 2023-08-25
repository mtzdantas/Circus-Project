// Universidade Federal do Rio Grande do Norte
// Disciplina DCT1106 -- Programação
// Projeto Sistema de Gestão de um Circo
// Developed by Mateus Dantas de Oliveira

#include <stdio.h>
#include <stdlib.h>

void intro_ingressos(void);

void intro_profissional(void);
void profissional_eventos(void);
void profissional_relatorios(void);

void sobre(void);
void desenvolvedor(void);

char option;
int stop = 1;

int main(){
    while (stop == 1){
        system("clear||cls");
        printf("[1]Atrações\n"); printf("[2]Ingressos\n"); printf("[3]Sobre nós\n");
        printf("[4]Desenvolvedor\n"); printf("[5]Administração\n"); printf("[6]Sair\n");
        printf("DIGITE A OPÇÃO DESEJADA: ");
        scanf("%s", &option);
        switch (option){
            case '1':
                system("clear||cls");
                printf("ATRAÇÕES CADASTRADAS.\n");
                system("pause");
                break;
            case '2':
                intro_ingressos();
                break;
            case '3':
                sobre();
                break;
            case '4':
                desenvolvedor();
                break;
            case '5':
                printf("RECONHECIMENTO DE SENHA PARA ACESSAR O PROFISSIONAL.\n");
                system("pause");
                intro_profissional();
                break;
            case '6':
                printf("VOLTE SEMPRE!");
                stop = 0;
                break;
            default:
                printf("POR FAVOR, SELECIONE UMA OPÇÃO VÁLIDA.\n");
                system("pause");
                break;
        }
    }
}

void intro_ingressos(void){
    stop = 0;
    while (stop == 0){
        system("clear||cls");
        printf("[1]Comprar\n"); printf("[2]Cancelar\n"); printf("[3]Meu Carrinho\n");
        printf("[4]Finalizar\n"); printf("[5]Compras Realizadas\n"); printf("[6]Voltar\n");
        printf("DIGITE A OPÇÃO DESEJADA: ");
        scanf("%s", &option);
        switch (option){
            case '1':
                system("clear||cls");
                printf("COMPRAR\n"); // Aqui terá que informar o código do show que será consultado ao clicar enter.
                system("pause");
                break;
            case '2':
                system("clear||cls");
                printf("CANCELAR COMPRAS\n"); // Aqui terá que informar o código do show que será consultado ao clicar enter.
                system("pause");
                break;
            case '3':
                system("clear||cls");
                printf("MEU CARRINHO\n"); // Aqui listará o que o cliente comprou até agora.
                system("pause");
                break;
            case '4':
                system("clear||cls");
                printf("FINALIZAR COMPRA\n"); // Aqui vai gerar um código para pagar e ao ser pago a compra é aprovada,
                system("pause"); // diminuindo a quantidade de vagas e cadastrando nas vendas daquele evento. Pedir número/CPF/nome.
                break;
            case '5':
                system("clear||cls");
                printf("COMPRAS REALIZADAS\n"); // Aqui mostrará ingressos comprados quando for informado nome completo/CPF.
                system("pause");
                break;
            case '6':
                // Aqui apaga o carrinho do cliente e volta para tela inicial.
                stop = 1;
                break; 
            default:
                printf("POR FAVOR, SELECIONE UMA OPÇÃO VÁLIDA.\n");
                system("pause");
                break;
        }
    }
}

void intro_profissional(void){
    stop = 0;
    while (stop == 0){
        system("clear||cls");
        printf("[1]Eventos\n"); // Usar no cadastro a localização, horário, data, preço
        printf("[2]Relatórios\n"); // vagas disponibilizadas e código de show (para acessar informações facilmente).
        printf("[3]Voltar\n");
        printf("DIGITE A OPÇÃO DESEJADA: ");
        scanf("%s", &option);
        switch (option){
            case '1':
                profissional_eventos();
                break;
            case '2':
                profissional_relatorios();
                break;
            case '3':
                stop = 1;
                break;
            default:
                printf("POR FAVOR, SELECIONE UMA OPÇÃO VÁLIDA.\n");
                system("pause");
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
        scanf("%s", &option);
        switch (option){
            case '1':
                system("clear||cls");
                printf("LISTA DE EVENTOS.\n");
                system("pause");
                break;
            case '2':
                system("clear||cls");
                printf("CADASTRAR EVENTOS\n");
                system("pause");
                // Usar no cadastro a localização, horário, data, preço, vagas disponibilizadas e código de show.
                break;
            case '3':
                system("clear||cls");
                printf("CANCELAR EVENTO.\n");
                system("pause");
                break;
            case '4':
                system("clear||cls");
                printf("ALTERAR DADOS DE EVENTO.\n");
                system("pause");
                break;
            case '5':
                stop = 0;
                break;
            default:
                printf("POR FAVOR, SELECIONE UMA OPÇÃO VÁLIDA.\n");
                system("pause");
                break;
        }
    }
}

void profissional_relatorios(void){
    system("clear||cls");
    printf("GERANDO RELATÓRIOS...\n"); // Informações de quantas vendas foram feitas, e quanto foi arrecatado.
    system("pause");
}

void desenvolvedor(void){
    system("clear||cls");
    printf("~ DESENVOLVEDOR \n"); printf("===================\n\n");
    printf("O projeto foi desenvolvido com o intuito de melhorar a gestão\n");
    printf("de eventos e ingressos de um circo, trazendo praticidade para\n");
    printf("clientes e funcionários.\n");
    printf("~ Developed By Mateus Dantas de Oliveira.\n");
    system("pause");
}

void sobre(void){
    system("clear||cls");
    printf("~ SOBRE NÓS \n"); printf("===============\n\n");
    printf("Bem-vindos ao nosso mágico mundo de diversão e maravilhas!\n");
    printf("Aqui, no nosso amado circo, estamos prontos para transportar\n");
    printf("você para um universo de encanto, risos e espetáculos incríveis.\n");
    printf("Permita-nos apresentar o 'GRAN C-IRCO' - um lugar onde os sonhos\n");
    printf("ganham vida sob a grande lona e onde a imaginação não tem limites.\n");
    system("pause");
}
