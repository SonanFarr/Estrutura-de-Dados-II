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

    void troca(Track &a, Track &b);
    void heapify(Track *vet, int i, int n);
    void constroiHeap(Track *vet, int n);
    void heapSortRec(Track *vet, int n);

    void heapSort(Track *vet, int n);

    void medeDesempenho(fstream &arq, int n);

    Track *criaVetorTrack(fstream &arq, int n);

  private:


};

#endif