#include <iostream>
using std::cout; 



//Busca Sequencial: nao necessariamente o vetor esta ordenado
bool search( int v[],int size_vec, int num){
	int i = 0;
	while((i<size_vec) and (v[i]!=num)){
		i++;
	}
	if(i<size_vec) return true;
	else return false; 
}

int seq_search( int v[],int size_vec, int num){
	int i = 0;
	while((i<size_vec) and (v[i]!=num)){
		i++;
	}
	if(i<size_vec) return i;
	else return -1; 
}

//Binary Search -- recursive function !
int _bin_search(int v[], int left, int right, int x ){
	int meio = (left + right)/2;
	if (left > right)
		return -1;

	if (v[meio] == x)
	return meio;
	if (x > v[meio])
	return (_bin_search(v, meio+1, right, x));
	else return (_bin_search(v, left, meio-1, x));
}

int bin_search( int v[],int size_vec, int num ){
	return (_bin_search(v, 0, size_vec-1, num ));
}

// Selection Sort: O(n^2)
void selection_sort(int v[], int size){
	int i, j, min, aux;
	for (i = 0; i < size - 1; i++) { 
		min = i;
		for (j = i + 1; j < size; j++)
			if (v[j] < v[min])	min = j;

		// Troca dos menores valores, de acordo com a pos.
		// do vetor
		aux = v[i];
		v[i] = v[min];
		v[min] = aux;
		}
}

// insertion_sort: O(n) ~ O(n^2)
void insertion_sort(int v[], int size){
	int i, j, aux;

	for (j = 1; j < size; j++) { 
		aux = v[j]; 	

		for (i = j; (i > 0) && (aux < v[ i-1 ]); i--)
			v[ i ] = v[ i - 1];

		v[ i ] = aux;

	}
}

// Bubble_sort: O(n^2)
void bubble_sort(int v[], int size){
	int i, j, min, aux;
	for ( i = 0; i < size; i++) {
		for ( j = 1; j < size; j++)
		if (v[j-1] > v[j]) { // troca entre valores
			aux = v[j] ;
			v[j] = v[j-1];
			v[j-1] = aux;
		} 
	}
}


// Bubble_sort improved: O(n) in best case
void bubble_sort_v2(int v[], int size){
	int i = 0, j, min, aux;
	bool troca = true;
	while(i < size && (troca)) {
		troca = false;
		for ( j = 1; j < size; j++)
		if (v[j-1] > v[j]) { // troca entre valores
			aux = v[j] ;
			v[j] = v[j-1];
			v[j-1] = aux;
			troca = true;
		} 
	}
}
