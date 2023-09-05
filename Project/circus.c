// Universidade Federal do Rio Grande do Norte
// Disciplina DCT1106 -- Programação
// Projeto Sistema de Gestão de um Circo
// Developed by Mateus Dantas de Oliveira

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void intro_ingressos(void);
void ingressos_comprar(void);
void ingressos_cancelar(void);
void ingressos_carrinho(void);
void ingressos_finalizar(void);
void ingressos_comprados(void);
void ingressos_sair(void);

void sobre(void);
void desenvolvedor(void);

void verificar_profissional(void);
void intro_profissional(void);
void profissional_eventos(void);
void eventos_listar(void);
void eventos_cadastrar(void);
void eventos_cancelar(void);
void eventos_alterar(void);
void profissional_relatorios(void);

void opcao_invalida(void);

int option;
int stop = 1;

int main(void){
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
                verificar_profissional();
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



void intro_ingressos(void){
    stop = 0;
    while (stop == 0){
        system("clear||cls");
        wprintf(L"===============================\n        ~ GRAN C-IRCO ~\n           INGRESSOS\n===============================\n");
        wprintf(L"[1]Comprar\n"); wprintf(L"[2]Cancelar\n"); wprintf(L"[3]Meu Carrinho\n");
        wprintf(L"[4]Finalizar\n"); wprintf(L"[5]Compras Realizadas\n"); wprintf(L"[6]Voltar\n");
        wprintf(L"DIGITE A OPÇÃO DESEJADA: ");
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
                ingressos_comprados();
                break;
            case 6:
                ingressos_sair();
                break; 
            default:
                opcao_invalida();
                break;
        }
    }
}

void ingressos_comprar(void){
    system("clear||cls");
    wprintf(L"===============================\n        ~ GRAN C-IRCO ~\n            COMPRAR\n===============================\n");
    wprintf(L"COMPRAR\n"); // Aqui terá que informar o código do show que será consultado ao clicar enter.
    wprintf(L"\n- PRESSIONE ENTER PARA CONTINUAR.");
    getchar();
    fflush(stdin);
}

void ingressos_cancelar(void){
    system("clear||cls");
    wprintf(L"===============================\n        ~ GRAN C-IRCO ~\n            CANCELAR\n===============================\n");
    wprintf(L"CANCELAR COMPRAS\n"); // Aqui terá que informar o código do show que será consultado ao clicar enter.
    wprintf(L"\n- PRESSIONE ENTER PARA CONTINUAR.");
    getchar();
    fflush(stdin);
}

void ingressos_carrinho(void){
    system("clear||cls");
    wprintf(L"===============================\n        ~ GRAN C-IRCO ~\n            CARRINHO\n===============================\n");
    wprintf(L"MEU CARRINHO\n"); // Aqui listará o que o cliente comprou até agora.
    wprintf(L"\n- PRESSIONE ENTER PARA CONTINUAR.");
    getchar();
    fflush(stdin);
}

void ingressos_finalizar(void){
    system("clear||cls");
    wprintf(L"===============================\n        ~ GRAN C-IRCO ~\n           FINALIZAR\n===============================\n");
    wprintf(L"FINALIZAR COMPRA\n"); // Aqui vai gerar um código para pagar e ao ser pago a compra é aprovada,
    wprintf(L"\n- PRESSIONE ENTER PARA CONTINUAR.");
    getchar(); // diminuindo a quantidade de vagas e cadastrando nas vendas daquele evento. Pedir número/CPF/nome.
    fflush(stdin);
}

void ingressos_comprados(void){
    system("clear||cls");
    wprintf(L"===============================\n        ~ GRAN C-IRCO ~\n       COMPRAS ANTERIORES\n===============================\n");
    wprintf(L"COMPRAS REALIZADAS\n"); // Aqui mostrará ingressos comprados quando for informado nome completo/CPF.
    wprintf(L"\n- PRESSIONE ENTER PARA CONTINUAR.");
    getchar();
    fflush(stdin);
}

void ingressos_sair(void){
    // Aqui apaga o carrinho do cliente e volta para tela inicial.
    stop = 1;
}



void verificar_profissional(void){
    char entrar[2][9] = {"circo", "circo123"};
    char tryentrar[2][9];
    int checklog = 1, checksen = 1, cancel = 1;
    while (checklog != 0 || checksen != 0){
        system("clear||cls");
        wprintf(L"===============================\n        ~ GRAN C-IRCO ~\n       LOGIN EMPRESARIAL\n===============================\n");
        wprintf(L"INFORME O LOGIN:\n");
        gets(tryentrar[0]);
        fflush(stdin);
        wprintf(L"INFORME A SENHA:\n");
        gets(tryentrar[1]);
        fflush(stdin);
        checklog = strcmp(entrar[0], tryentrar[0]);
        checksen = strcmp(entrar[1], tryentrar[1]);
        if (checklog == 0 && checksen == 0) {
            wprintf(L"LOGIN REALIZADO COM SUCESSO.\n");
            wprintf(L"\n- PRESSIONE ENTER PARA CONTINUAR.");
            getchar();
            fflush(stdin);
            intro_profissional();
        }
        else {
            wprintf(L"LOGIN OU SENHA INCORRETOS.\n");
            wprintf(L"DIGITE '2' PARA SAIR E OUTRA TECLA PARA CONTINUAR.\n");
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
        wprintf(L"===============================\n        ~ GRAN C-IRCO ~\n     BEM VINDO FUNCIONÁRIO\n===============================\n");
        wprintf(L"[1]Eventos\n"); // Usar no cadastro a localização, horário, data, preço
        wprintf(L"[2]Relatórios\n"); // vagas disponibilizadas e código de show (para acessar informações facilmente).
        wprintf(L"[3]Voltar\n");
        wprintf(L"DIGITE A OPÇÃO DESEJADA: ");
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
                opcao_invalida();
                break;
        }
    }    
}            

void profissional_eventos(void){
    stop = 1;
    while (stop == 1){
        system("clear||cls");
        wprintf(L"===============================\n        ~ GRAN C-IRCO ~\n            EVENTOS\n===============================\n");
        wprintf(L"[1]Listar\n"); wprintf(L"[2]Cadastrar\n"); wprintf(L"[3]Cancelar\n");
        wprintf(L"[4]Alterar\n"); wprintf(L"[5]Voltar\n");
        wprintf(L"DIGITE A OPÇÃO DESEJADA: ");
        scanf("%d", &option);
        fflush(stdin);
        switch (option){
            case 1:
                eventos_listar();
                break;
            case 2:
                eventos_cadastrar();
                break;
            case 3:
                eventos_cancelar();
                break;
            case 4:
                eventos_alterar();
                break;
            case 5:
                stop = 0;
                break;
            default:
                opcao_invalida();
                break;
        }
    }
}

void eventos_listar(void){
    system("clear||cls");
        wprintf(L"===============================\n        ~ GRAN C-IRCO ~\n          ESPETÁCULOS\n===============================\n");
    wprintf(L"LISTA DE EVENTOS.\n");
    wprintf(L"\n- PRESSIONE ENTER PARA CONTINUAR.");
    getchar();
    fflush(stdin);
}

void eventos_cadastrar(void){
    system("clear||cls");
    wprintf(L"===============================\n        ~ GRAN C-IRCO ~\n           CADASTRAR\n===============================\n");
    wprintf(L"CADASTRAR EVENTOS\n");
    wprintf(L"\n- PRESSIONE ENTER PARA CONTINUAR.");
    getchar();
    fflush(stdin);
    // Usar no cadastro a localização, horário, data, preço, vagas disponibilizadas e código de show.
}

void eventos_cancelar(void){
    system("clear||cls");
        wprintf(L"===============================\n        ~ GRAN C-IRCO ~\n            CANCELAR\n===============================\n");
    wprintf(L"CANCELAR EVENTO.\n");
    wprintf(L"\n- PRESSIONE ENTER PARA CONTINUAR.");
    getchar();
    fflush(stdin);
}

void eventos_alterar(void){
    system("clear||cls");
        wprintf(L"===============================\n        ~ GRAN C-IRCO ~\n            ALTERAR\n===============================\n");
    wprintf(L"ALTERAR DADOS DO EVENTO.\n");
    wprintf(L"\n- PRESSIONE ENTER PARA CONTINUAR.");
    getchar();
    fflush(stdin);
}

void profissional_relatorios(void){
    system("clear||cls");
    wprintf(L"===============================\n        ~ GRAN C-IRCO ~\n           RELATÓRIO\n===============================\n");
    wprintf(L"GERANDO RELATÓRIOS...\n"); // Informações de quantas vendas foram feitas, e quanto foi arrecatado.
    wprintf(L"\n- PRESSIONE ENTER PARA CONTINUAR.");
    getchar();
    fflush(stdin);
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



void opcao_invalida(void){
    system("clear||cls");
    wprintf(L"===============================\n        ~ GRAN C-IRCO ~\n        ERRO ENCONTRADO\n===============================\n");
    wprintf(L"POR FAVOR, SELECIONE UMA OPÇÃO VÁLIDA.\n");
    wprintf(L"\n- PRESSIONE ENTER PARA CONTINUAR.");
    getchar();
    fflush(stdin);
    system("clear||cls");
}
