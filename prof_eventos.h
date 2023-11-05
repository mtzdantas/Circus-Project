void eventos_listar(void);
void eventos_cadastrar(void);
void eventos_cancelar(void);
void eventos_alterar(void);
void opcao_invalida(void);
void cadastra_evento(void);

typedef struct Eventos{
    char status;
    int showcod;
    char data[12];
    char local[61]; 
    char horario[6];
    int preco; 
    int vagas;
} Eventos;
