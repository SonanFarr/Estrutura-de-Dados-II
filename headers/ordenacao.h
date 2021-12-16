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
    ~Ordenacao();

    //? Funções Auxiliares Gerais ------------------------------------------
    void troca(Track &a, Track &b);
    Track *criaVetorTrack(fstream &arq, int n);

    //? Funções Auxiliares HeapSort ----------------------------------------
    void heapify(Track *vet, int i, int n);
    void constroiHeap(Track *vet, int n);
    void heapSortRec(Track *vet, int n);

    //? Funções Auxiliares QuickSort ---------------------------------------
    void quickSortRec(Track *vet, int ini, int fim);
    int particiona(Track *vet, int ini, int fim);
    Track medianaDeTres(Track *vet, int ini, int fim);

    //? Funções Auxiliares SelectionSort ---------------------------------------
    void selectionSortRec(Track *vet, int ini, int fim);

    //? Algorítimos de Ordenação -------------------------------------------
    void heapSort(ifstream &arqDat, ofstream &outfile, fstream &arq);
    void quickSort(ifstream &arqDat, ofstream &outfile, fstream &arq);
    void selectionSort(ifstream &arqDat, ofstream &outfile, fstream &arq);

    //? Função de medida de Desempenho -------------------------------------
    void medeDesempenho(string dir, fstream &arq, int n);

  private:


};

#endif