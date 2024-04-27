#define MAX_CONTATOS 255
#define TAM_NOME 50
#define TAM_SOBRENOME 50
#define TAM_TELEFONE 15
#define TAM_EMAIL 50
#define TOTAL 100

// Definição da estrutura de um contato
typedef struct {                 // strutura de dados Contato
  char nome[TAM_NOME];           // char nome recebe TAM_NOME
  char sobrenome[TAM_SOBRENOME]; // char nome recebe TAM_SOBRENOME
  char telefone[TAM_TELEFONE];   // char telefeone recebe TAM_TELEFONE
  char email[TAM_EMAIL];         // char telefeone recebe TAM_TELEFONE
} Contato;

typedef enum {
  OK,
  MAXX_CONTATOS,
  SEM_CONTATOS,
  NAO_LOCALIZADO,
  ABRIR,
  FECHAR,
  ESCREVER,
  CARREGAR
} ERROS;

typedef ERROS (*funcao)(Contato[], int *);

ERROS adicionar(Contato tarefas[], int *pos);
ERROS deletar(Contato tarefas[], int *pos);
ERROS listar(Contato tarefas[], int *pos);
ERROS carregar(Contato tarefas[], int *pos);
ERROS salvar(Contato tarefas[], int *pos);

void clearBuffer();