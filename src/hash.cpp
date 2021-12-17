#include <iostream>
#include <chrono>
#include <cstdlib>
#include <string>
#include <vector>
#include <math.h>
#include "../headers/track.h"
#include "../headers/review.h"
#include "../headers/ordenacao.h"
#include "../headers/hash.h"

using namespace std;
using namespace std::chrono;

using namespace std;

//? Constructor ---------------------------------------------------------------
Hash::Hash(int tamanho){
    this->tamanho = tamanho;
    quantItens = 0;
    vet = new Version *[tamanho];

    for(int i = 0; i<tamanho; i++){
        vet[i] = nullptr;
    }
}

//? Destructor ----------------------------------------------------------------
Hash::~Hash(){
    
    Version *aux;
    Version *ant; 

    for(int i = 0; i<tamanho; i++){
        aux = vet[i];

        while(aux != nullptr){
            ant = aux;
            aux = aux->prox;
            delete ant;
        }
    }

    delete[] vet;
}

//? Funções Principais --------------------------------------------------------
void Hash::insere(Track *version){
    int chave = converteEmInteiro(version);

    int functionHash = chave % tamanho;

    Version *aux = vet[functionHash];
    Version *ant = nullptr;

    while(aux != nullptr){
        ant = aux;

        if(aux->getTrack()->app_version == version->app_version){
            aux->quantidade = aux->quantidade +1;
        }

        aux = aux->prox;
    }

    if (aux == nullptr){
        aux = new Version(version);
        quantItens = quantItens + 1;

        if(aux == nullptr){
            vet[functionHash] = aux;
        }
        else{
            ant->prox = aux;
        }
    }
    else{
        aux->setTrack(version);
    }
}

void Hash::versionFrequentes(){

}

void Hash::quickSortRecHash(Version **vet, int ini, int fim){
    if(ini < fim){
        int p = particionaHash(vet, ini, fim);
        quickSortRecHash(vet, ini, p-1);
        quickSortRecHash(vet, p+1, fim);
        return;
    }
}

void Hash::imprimeHash(){

}

//? Funções Auxiliares --------------------------------------------------------
int converteEmInteiro(Track *track){

}

int busca(){

}

//? Funções Auxilares de Ordenação --------------------------------------------
int particionaHash(Version **vet, int ini, int fim){
    Version *pivo = medianaDeTresHash(vet, ini, fim);

    int i = ini, j = fim-1;
    while(true)
    {
        while(i < fim && vet[i]->quantidade < pivo->quantidade)
            i++;
        while(j >= ini && vet[j].upvotes > pivo.upvotes)
            j--;

        if(i < j)
        {
            troca(vet[i], vet[j]);
            trocas = trocas + 1;
            comparacoes = comparacoes +1;
            i++;
            j--;
        }
        else
            break;
    }
    troca(vet[i], vet[fim]);
    trocas = trocas + 1;
    return i;
}
        
Version medianaDeTresHash(Version **vet, int ini, int fim){

}