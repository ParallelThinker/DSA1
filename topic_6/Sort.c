/**
Nome: Thiago Martins
Ra: 790964
**/

#include <stdio.h>
#include <stdlib.h>

/**
* Recebe o vetor v  de tamanho n e o ordena
**/
void sort(int * v,int n){
 //Cria a variável auxiliar
 int aux = 0;

 //Percorre o vetor em i
 for(int i = 0; i < n; i++){
    //Percorre o vetor em J
    for(int j = 0; j < n; j++){

        //Verifica se a posição i < posção j
        if(v[i] < v[j])
        {
            //Efetua a troca das posições
            aux = v[i];
            v[i] = v[j];
            v[j] = aux;
        }
    }
 }
}

int main(){

    //entrada 1 numero de elementos do vetor a ser ordenado
    //entrada 2 lista de elementos a ser inserido em sequencia na árvore
    int i, n;
    scanf("%d",&n);
    int * v = (int *)malloc(n*sizeof(int));
    for(i = 0; i < n; i++)
        scanf("%d",&v[i]);

    sort(v,n);

    //imprime o vetor ordenado
    for(i = 0; i < n-1; i++)
        printf("%d,",v[i]);
    printf("%d", v[i]);



    free(v);
    return 0;
}


