#ifndef HASH_H
#define HASH_H


#include <iostream>
#include "../headers/track.h"
#include "../headers/review.h"
#include "../headers/version.h"

using namespace std;

class Hash{
    public:
        //? Constructors ------------------------------------- 
        Hash(int tamanho, string dir);

        //? Destructor ---------------------------------------
        ~Hash();

        //? Funções Principais -------------------------------
        void insere(Track *version);
        void versionFrequentes(string dir, fstream &arq);
        void quickSortRecHash(Version **vet, int ini, int fim);
        void imprimeHash();

        //? Funções Auxiliares -------------------------------
        int converteEmInteiro(Track *track);
        int busca();

        //? Funções Auxilares de Ordenação -------------------
        int particionaHash(Version **vet, int ini, int fim);
        Version *medianaDeTresHash(Version **vet, int ini, int fim);


    private:
        Version **vet;
        string dir;
        int tamanho;
        int quantItens;
};


#endif