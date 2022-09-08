#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Struct de dados
struct list_rec {
    int info;
    struct list_rec *next;
    struct list_ant *ant;
};

typedef struct list_rec  Rec;

//Struct lista
typedef struct{
    int nelem;
    Rec *head;
    Rec *topo;
} Lista;

//Declara uma lista auxiliar
Lista aux;

//Cria a lista setando os parametros iniciais
void CriarLista(Lista *L)
{
    L = malloc(sizeof(Lista));
    L->nelem = 0;
    L->head = NULL;
    L->topo = NULL;
}

//Insere o primeiro elemento da lista
void Insere_Prim(Lista *L, int elem)
{
    Rec *p;
    p = malloc(sizeof(Rec));

    //Insere o elemento
    p->info = elem;

    //Primeiro elemento nao tem anterior nem proximo
    p->next = NULL;
    p->ant = NULL;

    //Primeiro elemento o topo e o head
    L->head = p;
    L->topo = p;

    //Adiciona 1 a quantidade de elementos
    L->nelem++;
}

//Insere o elemento na lista
void Insere_Depois(Lista *L,int v, Rec *k)
{
    //Cria um novo espaco de memoria
    Rec *j = malloc(sizeof(Rec));

    //Atribui o valor
    j->info = v;

    //Por ser o ultimo elemento ele nao tem proximo
    j->next = NULL;

    //Atribui o elemento anterior da nova variavel e atribui o proximo do elemento anterior
    j->ant = k;
    k->next = j;

    //Adiciona 1 a quantidade de elementos
    L->nelem++;

    //Define o topo da pilha
    L->topo = j;
}

//Funcao que vai decidir se vai ser colocado como primeiro elemento ou nao
bool Insere(Lista *L, int v)
{
    //Verifica se ja existe elementos na pilha
    if(vazia(L) == true)
    {
        //Insere o primeiro elemento da pilha
        Insere_Prim(L, v);
        return true;
    }

    //Insere o elemento na posicao seguinte
    Insere_Depois(L, v, L->topo);

    return true;
}

int vazia(Lista *L)
{
    //Verifica se a pilha esta vazia
    if(L->nelem == 0)
        return true;

    return false;
}

//Remove um elemento da pilha
int Remove(Lista *L)
{
    //Declaracao de variavel
    int valor;
    Rec *p = L->topo;
    valor = p->info;

    //Verifica se a pilha esta vazia
    if(vazia(L) == true)
    {
        return 0;
    }
    else
    {
        //Verifica se existe uma posicao anterior
        if(p->ant != NULL)
        {
            //Atribui vazio para o elemento
            Rec *k = p->ant;
            k->next = NULL;
        }

        //Recebe o elemento anterior como topo
        L->topo = p->ant;

        //Apaga o elemento
        free(p);

        //Diminui o numero de elementos da fila
        L->nelem--;
    }

    //Retorna o valor do elemento removido
    return valor;
}

//Imprime os dados da pilha
void imprime(Lista *L)
{
    //Declaracao de variaveis
    int valorRemovido;

    //Instancia a pilha auxiliar
    CriarLista(&aux);

    //Percorre a pilha principal
    while(vazia(L) != true)
    {
        //Pega o valor que foi removido
        valorRemovido = Remove(L);

        //Exibe o valor removido
        printf("\nElemento : %i", valorRemovido);

        //Insere na pilha auxiliar
        Insere(&aux, valorRemovido);
    }

   //Percorre a pilha auxiliar
   while(vazia(&aux) != true)
   {
       //Remove o valor da pilha auxiliar
       valorRemovido = Remove(&aux);

       //Insere o valor na pilha principal
       Insere(L, valorRemovido);
   }
}

int main()
{

    //Declaracao de variavel
    Lista dados;

    //Instancia a pilha
    CriarLista(&dados);

    //Testes
    Insere(&dados, 1);
    Insere(&dados, 2);
    Insere(&dados, 3);
    Insere(&dados, 4);

    Remove(&dados);
    imprime(&dados);
    printf("\n ----------------");

    Remove(&dados);
    imprime(&dados);

    printf("\n ----------------");
    Remove(&dados);
    Insere(&dados, 4);
    imprime(&dados);

    printf("\n ----------------");
    Remove(&dados);
    imprime(&dados);

   return 0;
}



