/*Bibliotecas utilizadas*/


typedef struct agenciabancaria Agenciabancaria;

typedef struct lista Lista;


/*Função para cadastra uma nova agencia bancaria, alocando memoria*/

//Função para cadastra uma nova agencia bancaria, alocando memoria

Agenciabancaria *criar_agencia(char *nome, int codigo, char* localizacao, char* horario);
// funçao para ordenar contas
Lista * lista_insere_ordena(Lista *k, Contabancaria *conta);
// funcao para cadastrar cliente em agencia 
Agenciabancaria *cadastrar_cliente (Contabancaria *contabancaria, Agenciabancaria *agenciabancaria);
// funcao para cadastrar conta bancaria
Agenciabancaria *cadastrar_conta(Agenciabancaria* agencia);
// funcao para listar agencias cadastradas
void listar_agencias(Agenciabancaria **agencias, int qntagencias);
// funcao para localizar contas
void localizar_conta(Agenciabancaria **agencias, int qntagencias, int numero);
// funcao para remove conta cadastrada
void remove_conta(Agenciabancaria **agencia, int qntcontas)
//Função para salva arquivos

void agencia_salva(Agenciabancaria *agenciabancaria);


// função libera agencias vai liberar a memoria ocupada
void libera_agencia(Agenciabancaria ** age ,FILE * fp);

*/
