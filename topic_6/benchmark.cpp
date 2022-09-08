#include <iostream>
#include <cstdlib>
#include <chrono>


#include "include/sorting.h"

using namespace std;

int *gera_vetor(int size_vec);
int *copia_vetor(int v[], int size_vec);
void display(int v[], int size);


// Inicio do programa
int main(int argc, char const *argv[])
{	
	srand(777);
	cout << "Analise de Ordenacao e Pesquisa em vetores primitivos !\n";
	//Criacao de vetores de tamanho n
	const int size_vector = 1000;
	int *v1, *v2;
	v1 = gera_vetor(size_vector);
	
	v2 = gera_vetor(size_vector);
	
	// Cria copia dos vetores criados acima 
	int *v1_select = copia_vetor(v1, size_vector);
	int *v1_insertion = copia_vetor(v1, size_vector); 
	int *v1_bubble = copia_vetor(v1, size_vector); 
	int *v1_bubble_v2 = copia_vetor(v1, size_vector);


	/*
	Definidos os vetores(desordenados), usaremos as funcoes de ordenacao 
	Para realizacao de consultas dentro do vetor.
	Das funcoes de ordenacao, teremos:
	*/

	//Caso 1  : Selection Sort

	//Tempo antes do processo
	auto start = chrono::high_resolution_clock::now();
	selection_sort(v1_select, size_vector);

	//Tempo depois do processo e seu tempo de duracao
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double, std::milli> selection_time = end - start;
	cout << "[Finished selection_sort  in  " << selection_time.count() <<"ms]" << endl;

	//Caso 2  : Insertion Sort
	start = chrono::high_resolution_clock::now();
	insertion_sort(v1_insertion, size_vector);
	//Tempo depois do processo e seu tempo de duracao
	end = chrono::high_resolution_clock::now();
	chrono::duration<double, std::milli> insert_time = end - start;
	cout << "[Finished insertion_sort  in  " << insert_time.count() <<"ms]" << endl;
	

	//Caso 3  : Bubble Sort

	//Cronometragem de tempo inicial 
	start = chrono::high_resolution_clock::now();
	
	bubble_sort(v1_bubble, size_vector);

	//Tempo depois do processo e seu tempo de duracao
	end = chrono::high_resolution_clock::now();
	chrono::duration<double, std::milli> bubble_time = end - start;
	
	cout << "[Finished bubble_sort     in  " << bubble_time.count() <<"ms]" << endl;

	//Caso 3.1: Bubble Sort c/ melhoria
	start = chrono::high_resolution_clock::now();
	bubble_sort_v2(v1_bubble_v2, size_vector);
	//Tempo depois do processo e seu tempo de duracao
	end = chrono::high_resolution_clock::now();
	chrono::duration<double, std::milli> bubble_time_v2 = end - start;
	cout << "[Finished bubble_version2 in  " << bubble_time.count() <<"ms]" << endl;


	//Verifica item presente na lista, por busca binaria
	int num_sorteado = v1[rand()%size_vector];

	cout << "num_sorteado: " << num_sorteado <<endl; 


	start = chrono::high_resolution_clock::now();
	int pos_bin = bin_search(v1_bubble, size_vector, num_sorteado);
	end = chrono::high_resolution_clock::now();
	chrono::duration<double, std::milli> bin_search_time = end - start;


	start = chrono::high_resolution_clock::now();
	int pos_seq   = seq_search(v1_bubble, size_vector, num_sorteado);
	end = chrono::high_resolution_clock::now();
	chrono::duration<double, std::milli> seq_search_time = end - start;

	cout << "Posicao em retornada por bin_search e seq_search: " << pos_bin <<", " << pos_seq << endl;
	cout << "Tempo estimado de Pesquisa:" <<endl;
	cout << "\t seq_search: " << seq_search_time.count() << "ms" <<endl;
	cout << "\t bin_search: " << bin_search_time.count() << "ms" <<endl;


	//Analise de Tempo na busca entre os mecanismos de busca





	return 0;
}

int *gera_vetor(int size_vec){
	int *v = new int[size_vec];
	int it = 0, rand_val;
	while(it<size_vec){
		//Obtem um numero aleatorio
		rand_val = rand();
		// evita a inclusao de numeros repetidos em v3
		if(!search(v,it,rand_val)) v[it] = rand_val;		
		it++;
	}

	return v;
}

int *copia_vetor(int v[], int size_vec){
	int *cp_vec = new int[size_vec];
	for(int i = 0; i<size_vec; i++)
		cp_vec[i] = v[i];	
	return cp_vec;
}

void display(int v[], int size){
	cout << "Vetor: ";
	for(int i = 0; i < size; i ++)
		cout << v[i] << " ";
	cout << "\n";
}
