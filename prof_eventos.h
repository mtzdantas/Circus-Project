void eventos_listar(void);
void eventos_cadastrar(void);
void eventos_cancelar(void);
void eventos_alterar(void);
void opcao_invalida(void);
void cadastra_evento(void);
int compararPorData(const void *a, const void *b);
int ordenar(void);
void atualizarEvento(int codigo, int novoDia, int novoMes, int novoAno, const char novoLocal[61], const char novoHorario[6], int novoPreco, int novaVagas);

typedef struct Eventos{
    char status;
    int showcod;
    char local[61]; 
    char horario[6];
    int preco; 
    int vagas;
    int vendas;
    int dia;
    int mes;
    int ano;
} Eventos;
