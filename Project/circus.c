// Universidade Federal do Rio Grande do Norte
// Disciplina DCT1106 -- Programação
// Projeto Sistema de Gestão de um Circo
// Developed by Mateus Dantas de Oliveira

#include <stdio.h>
#include <stdlib.h>

void intro_cliente(void);
void intro_profissional(void);
void cadastro(void);
void sobre(void);

char option[2];

int main(){
    system("clear||cls");
    printf("[1]Entrar\n"); // Caso coloque uma senha existente para um cliente, entra na função intro_cliente e
    printf("[2]Cadastrar\n"); // se colocar uma existente para um funcionário, entra na função intro_profissional.
    printf("[3]Sobre nós\n"); // E se não tiver cadastro, seleciona a opção e vai para tela de cadastro.
    printf("[4]Sair\n");
    printf("DIGITE A OPÇÃO DESEJADA: ");
    scanf("%s", option);
    switch (option[0]){
        case '1':
            intro_cliente(); // Fazer verificação se foi feito o login profissional ou do cliente.
            intro_profissional();
            break;
        case '2':
            cadastro();
            break;
        case '3':
            sobre();
            break;
        case '4':
            printf("VOLTE SEMPRE!");
            break;
        default:
            printf("POR FAVOR, SELECIONE UMA OPÇÃO VÁLIDA.");
            break;
    }
    return 0; // Usar estrutura de repetição para sair do código apenas quando selecionar para sair.
}
void intro_cliente(void){
    system("clear||cls");
    printf("[1]Próximas atrações\n");
    printf("[2]Ingressos\n"); // Colocar um módulo com opções de Comprar, Cancelar e Ver Carrinho.
    printf("[3]Finalizar compra\n");
    printf("[4]Compras realizadas\n");
    printf("[5]Reembolso\n");
    printf("[6]Sair\n");
    printf("DIGITE A OPÇÃO DESEJADA: ");
    scanf("%s", option);
}
void intro_profissional(void){
    system("clear||cls");
    printf("[1]Eventos\n"); // Colocar um CRUD para os eventos e usar no cadastro a localização, horário, data, preço
    printf("[2]Gerar relatório\n"); // vagas disponibilizadas e código de show (para acessar informações facilmente).
    printf("DIGITE A OPÇÃO DESEJADA: ");
    scanf("%s", option);
}            
void cadastro(void){
    system("clear||cls");
    printf("SISTEMA DE CADASTROS AQUI!\n");
    system("pause");
}        
void sobre(void){
    system("clear||cls");
    printf("TEXTO SOBRE NÓS AQUI!\n");
    system("pause");
}
