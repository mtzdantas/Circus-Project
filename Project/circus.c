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

char option[2];

int main(){
    system("clear||cls");
    printf("[1]Atrações\n"); printf("[2]Ingressos\n"); printf("[3]Sobre nós\n");
    printf("[4]Desenvolvedor\n"); printf("[5]Sair\n"); printf("[0]Funcionários\n");
    printf("DIGITE A OPÇÃO DESEJADA: ");
    scanf("%s", option);
    switch (option[0]){
        case '0':
            printf("RECONHECIMENTO DE SENHA PARA ACESSAR O PROFISSIONAL.");
            intro_profissional();
            break;
        case '1':
            printf("ATRAÇÕES CADASTRADAS.");
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
            printf("VOLTE SEMPRE!");
            break;
        default:
            printf("POR FAVOR, SELECIONE UMA OPÇÃO VÁLIDA.");
            break;
    }
    return 0; // Usar estrutura de repetição para sair do código apenas quando selecionar para sair.
}

void intro_ingressos(void){
    system("clear||cls");
    printf("[1]Comprar\n"); printf("[2]Cancelar\n"); printf("[3]Meu Carrinho\n");
    printf("[4]Finalizar\n"); printf("[5]Compras Realizadas\n"); printf("[6]Voltar\n");
    printf("DIGITE A OPÇÃO DESEJADA: ");
    scanf("%s", option);
    switch (option[0]){
        case '1':
            printf("TELA DE COMPRAR"); // Aqui terá que informar o código do show que será consultado ao clicar enter.
            break;
        case '2':
            printf("CANCELAR COMPRAS"); // Aqui terá que informar o código do show que será consultado ao clicar enter.
            break;
        case '3':
            printf("MEU CARRINHO"); // Aqui listará o que o cliente comprou até agora.
            break;
        case '4':
            printf("FINALIZAR COMPRA"); // Aqui vai gerar um código para pagar e ao ser pago a compra é aprovada,
            break; // diminuindo a quantidade de vagas e cadastrando nas vendas daquele evento. Pedir número/CPF/nome.
        case '5':
            printf("COMPRAS REALIZADAS"); // Aqui mostrará ingressos comprados quando for informado nome completo/CPF.
            break;
        case '6':
            // Aqui apaga o carrinho do cliente e volta para tela inicial.
            break; 
        default:
            printf("POR FAVOR, SELECIONE UMA OPÇÃO VÁLIDA.");
            break;
    }
    return 0; // Usar estrutura de repetição para sair do código apenas quando selecionar para sair.
}

void intro_profissional(void){
    system("clear||cls");
    printf("[1]Eventos\n"); // Usar no cadastro a localização, horário, data, preço
    printf("[2]Relatórios\n"); // vagas disponibilizadas e código de show (para acessar informações facilmente).
    printf("[3]Voltar\n");
    printf("DIGITE A OPÇÃO DESEJADA: ");
    scanf("%s", option);
    switch (option[0]){
        case '1':
            profissional_eventos();
            break;
        case '2':
            profissional_relatorios();
            break;
        case '3':
            break;
        default:
            printf("POR FAVOR, SELECIONE UMA OPÇÃO VÁLIDA.");
            break;
    }      
}            

void profissional_eventos(void){
    system("clear||cls");
    printf("[1]Listar\n"); printf("[2]Cadastrar\n"); printf("[3]Cancelar\n");
    printf("[4]Alterar\n"); printf("[5]Voltar\n");
    printf("DIGITE A OPÇÃO DESEJADA: ");
    scanf("%s", option);
    // Usar no cadastro a localização, horário, data, preço, vagas disponibilizadas e código de show.
}

void profissional_relatorios(void){
    system("clear||cls");
    printf("GERANDO RELATÓRIOS..."); // Informações de quantas vendas foram feitas, e quanto foi arrecatado.
    system("pause");
}

void desenvolvedor(void){
    system("clear||cls");
    printf("O projeto foi desenvolvido com o intuito de melhorar a gestão\n");
    printf("de eventos e ingressos de um circo, trazendo praticidade para\n");
    printf("clientes e funcionários.\n");
    printf("~ Developed By Mateus Dantas de Oliveira.\n");
    system("pause");
}

void sobre(void){
    system("clear||cls");
    printf("Bem-vindos ao nosso mágico mundo de diversão e maravilhas!\n");
    printf("Aqui, no nosso amado circo, estamos prontos para transportar\n");
    printf("você para um universo de encanto, risos e espetáculos incríveis.\n");
    printf("Permita-nos apresentar o 'GRAN C-IRCO' - um lugar onde os sonhos\n");
    printf("ganham vida sob a grande lona e onde a imaginação não tem limites.\n");
    system("pause");
}