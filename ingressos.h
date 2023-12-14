void intro_ingressos(void);
void ingressos_comprar(void);
void ingressos_cancelar(void);
void ingressos_carrinho(void);
void ingressos_finalizar(void);
void ingressos_comprados(void);
void ingressos_sair(void);
void opcao_invalida(void);

typedef struct Cliente {
    char cpf[12];
    int compras[20];
    int dia;
    int mes;
    int ano;
} Cliente;