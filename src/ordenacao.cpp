#include <iostream>
#include <chrono>
#include <cstdlib>
#include <string.h>
#include <cstring>
#include <string>
#include "../headers/ordenacao.h"
#include "../headers/review.h"

using namespace std;
using namespace std::chrono;

Ordenacao::Ordenacao(){

}

Ordenacao::Ordenacao(int tamanho) {
  array = new Track [tamanho];
  setTamanho(tamanho);
  criaAleatorio();
  imprimeArray();
}

Ordenacao::~Ordenacao(){
  delete array;
}

void Ordenacao::setTamanho(int tamanho) {
  this->tamanho = tamanho;
}

int Ordenacao::getTamanho() {
  return this->tamanho;
}

//void Ordenacao::criaAleatorio() {
  //for(int i = 0; i < getTamanho(); i++) {
    //array[i] = rand() % getTamanho() * 2;
  //}
//}

void Ordenacao::imprimeArray() {
  for(int i = 0; i < getTamanho(); i++) {
    cout << array[i].upvotes << " ";
  }
    cout << endl;
}

// Algorítimos de Ordenação ----------------------------------------------------------------------------

void Ordenacao::selectionSort() {
  for(int i = 0; i < this->tamanho-1; i++) {
    int min = i;
    for(int j = i + 1; j < this->tamanho; j++) {
      if(array[j].upvotes < array[min].upvotes) 
        min = j;
    }
    //troca(array[i], array[min]); Necessário fazer a adaptação para a ordenação das tracks.
    imprimeArray();
  }
}

/**
 * @brief    Função principal para o algorítimo HeapSort.
 * 
 * @param v  Vetor de tracks que será ordenado.
 * @param n  Tamanho do vetor a ser ordenado.
 */
void Ordenacao::heapSort(Track *v, int n){

    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    heapSortRec(v, n);
    high_resolution_clock::time_point fim = high_resolution_clock::now();
    cout << duration_cast<duration<double>>(fim - inicio).count() << " segundos" << endl;
}

// Funções de medida de desempenho ---------------------------------------------------------------------

/**
 * @brief      Função principal para teste de desempenho dos algorítimos de ordenação.
 * 
 * @param arq  Arquivo binário para leitura dos registros.
 * @param n    Tamanho do vetor a ser criado. 
 */
void Ordenacao::medeDesempenho(fstream &arq, int n){
  int m = 3;

  Track *vet;
  Review r;

  for(int i=0; i<m; i++){
    r.criaVetorTrack(arq, vet, n);
    
    cout << "Vetor criado: " << endl;
    cout << "[";
    for(int i=0; i<n-1; i++){
      cout << vet[i].upvotes << ", ";
    }
    cout << vet[n-1].upvotes << "]";

    heapSort(vet, n);

    cout << "Vetor ordenado: " << endl;
    cout << "[";
    for(int i=0; i<n-1; i++){
      cout << vet[i].upvotes << ", ";
    }
    cout << vet[n-1].upvotes << "]";
  }

}

// Funções Auxiliares ----------------------------------------------------------------------------------

/**
 * @brief    Função auxiliar para trocar a posição entre dois elementos.
 * 
 * @param a  Elemento a.
 * @param b  Elemento b.
 */
void Ordenacao::troca(Track &a, Track &b) {
  Track aux = a;
  a = b;
  b = aux;
}

/**
 * @brief    Função auxiliar para manipulação da heap.
 * 
 * @param v  Vetor de tracks.
 * @param i  Índice auxiliar.
 * @param n  Tamanho do vetor de tracks.
 */
void Ordenacao::heapify(Track *v, int i, int n){
    while(i < n)
    {
        int filho = 2*i + 1;
        if(filho < n)
        {
            if(filho+1 < n && v[filho+1].upvotes > v[filho].upvotes)
                filho++;
            
            if(v[filho].upvotes > v[i].upvotes)
                troca(v[i], v[filho]);
        }
        i = filho;
    }
}

/**
 * @brief    Função auxiliar para criação da árvore heap.
 * 
 * @param v  Vetor de tracks.
 * @param n  Tamanho do vetor de tracks.
 */
void Ordenacao::constroiHeap(Track *v, int n){
    
    for(int i = n/2-1; i >= 0; i--)
        heapify(v, i, n);
}

/**
 * @brief    Função auxiliar para ordenação da heap. 
 * 
 * @param v  Vetor de tracks.
 * @param n  Tamanho do vetor de tracks.
 */
void Ordenacao::heapSortRec(Track *v, int n){
    
    constroiHeap(v, n);
    while(n > 0)
    {
        troca(v[0], v[n-1]);
        heapify(v, 0, n-1);
        n--;
    }
}