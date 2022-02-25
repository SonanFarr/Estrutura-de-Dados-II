#ifndef ORDENACAO_H
#define ORDENACAO_H


#include <iostream>
#include <chrono>
#include <cstdlib>
#include <string>
#include "../headers/registro.h"
#include "../headers/review.h"

using namespace std;
using namespace std::chrono;

using namespace std;

class Ordenacao{
  public:
    Ordenacao();
    ~Ordenacao();

    //? Funções Auxiliares Gerais ------------------------------------------
    void troca(int &a, int &b);
    int *criaVetorRegistro(fstream &arq, int n);

    //? Funções Auxiliares HeapSort ----------------------------------------
    void heapify(int *vet, int i, int n);
    void constroiHeap(int *vet, int n);
    void heapSortRec(int *vet, int n);

    //? Funções Auxiliares QuickSort ---------------------------------------
    void quickSortRec(int *vet, int ini, int fim);
    int particiona(int *vet, int ini, int fim);
    int medianaDeTres(int *vet, int ini, int fim);

    //? Funções Auxiliares SelectionSort ---------------------------------------
    void selectionSortRec(int *vet, int ini, int fim);

    //? Algorítimos de Ordenação -------------------------------------------
    void heapSort(ifstream &arqDat, ofstream &outfile, fstream &arq);
    void quickSort(ifstream &arqDat, ofstream &outfile, fstream &arq);
    void selectionSort(ifstream &arqDat, ofstream &outfile, fstream &arq);

    //? Função de medida de Desempenho -------------------------------------
    void medeDesempenho(string dir, fstream &arq, int n);

  private:


};

#endif