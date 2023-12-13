// REFERÊNCIA DA FUNÇÃO DE VALIDAR CPF:
// https://github.com/Mumber162/StyleC-Hair/blob/main/util.c
// PS: FOI FEITA PEQUENAS ALTERAÇÕES NAS SAÍDAS DE TEXTO.
#include <stdbool.h>

int validaCPF(char *cpf);
bool validaData(int dia, int mes, int ano);
bool validaCod(int codigo);
bool validaLocal(char local[]);
bool validaHorario(const char *horario);
bool validaNumeros(char input[]);
bool validaIngresso(int codIng);
void limpar_buffer();