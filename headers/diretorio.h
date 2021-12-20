#ifndef DIRETORIO_H
#define DIRETORIO_H


#include <iostream>
#include <chrono>
#include <cstdlib>
#include <string>
#include <vector>
#include "../headers/track.h"
#include "../headers/review.h"
#include "../headers/cesto.h"

using namespace std;
using namespace std::chrono;

using namespace std;
using namespace std::chrono;

class Diretorio
{
    private:
        int global;
        int tamanhoMaxCesto;
        int numBits;
        int numChaves;
        int cesto;
        //vector<Cesto*> cestos;

    public:
        Diretorio(int profundidade, int tamCesto);
        ~Diretorio();
        string hash(int n, int numBits);
        void inserir(int valor);
        bool encontrar(int valor);
        void duplicarDiretorio();
        //Cesto* dividirCesto(string chave); 
        int GetNumDeCestos();
        int GetNumDeChaves();
        int binarioDecimal(int n);

};

#endif