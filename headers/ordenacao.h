#ifndef ORDENACAO_H
#define ORDENACAO_H


#include <iostream>
#include <chrono>
#include <cstdlib>
#include <string>
#include "../headers/track.h"
#include "../headers/review.h"

using namespace std;
using namespace std::chrono;

using namespace std;

class Ordenacao{
  public:
    Ordenacao();
    Ordenacao(int tamanho);
    ~Ordenacao();

    // Funções importantes
    void criaAleatorio();
    void imprimeArray();

    // Getters e Setters
    void setTamanho(int tamanho);
    int getTamanho();

    // Ordenacoes
    void selectionSort();
    void heapSort(Track *v, int n);

    // Medida de Desempenho
    void medeDesempenho(fstream &arq, int n);

    // Funções auxiliares
    void troca(Track &a, Track &b);
    void heapify(Track *v, int i, int n);
    void constroiHeap(Track *v, int n);
    void heapSortRec(Track *v, int n);

  private:
    Track *array;
    int tamanho;

};

#endif