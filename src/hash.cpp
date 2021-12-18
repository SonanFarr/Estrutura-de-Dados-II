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
Hash::Hash(int tamanho, string dir){
    this->tamanho = tamanho;
    this->dir = dir;
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
            aux->quantidade = aux->quantidade + 1;
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

void Hash::versionFrequentes(string dir, fstream &arq){
    string dirArqDat = dir + "/input.dat";
    string dirOutfile = dir + "/outfileHash.txt";

     ifstream arqDat(dirArqDat, ios::in);
     ofstream outfile(dirOutfile, ios::app);

     arqDat.seekg(0);
     string line;

     getline(arqDat, line, '\n');

     int n = stoi(line);

     int tam = 1301;

     Ordenacao o;

     Track *vet = o.criaVetorTrack(arq, n);
     Hash tabela(tam, dir);
     
     for(int i=0; i<n; i++){
         tabela.insere(&vet[i]);
     }

     quickSortRecHash(tabela.vet, 0, tabela.tamanho);

     for(int i=tabela.tamanho; i>0; i--){
         outfile << "Versão: " << tabela.vet[i]->getTrack()->app_version << " - Quantidade: " << tabela.vet[i]->quantidade << endl; 
     }
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
int Hash::converteEmInteiro(Track *track){
    std::stringstream ss(track->app_version);

    string line;
    string aux;

    getline(ss, aux, '.');
    line = line + aux;
    getline(ss, aux, '.');
    line = line + aux;
    getline(ss, aux);
    line = line + aux;

    int app_version_int = stoi(line);
    
    return app_version_int;
}

int Hash::busca(){

}

//? Funções Auxilares de Ordenação --------------------------------------------
int Hash::particionaHash(Version **vet, int ini, int fim){
    Version *pivo = medianaDeTresHash(vet, ini, fim);

    int i = ini, j = fim-1;
    while(true)
    {
        while(i < fim && vet[i]->quantidade < pivo->quantidade)
            i++;
        while(j >= ini && vet[j]->quantidade > pivo->quantidade)
            j--;

        if(i < j)
        {
            swap(vet[i], vet[j]);
            i++;
            j--;
        }
        else
            break;
    }
    swap(vet[i], vet[fim]);
    return i;
}
        
Version *Hash::medianaDeTresHash(Version **vet, int ini, int fim){
    int meio = (ini+fim)/2;
    if(vet[ini]->quantidade > vet[fim]->quantidade){
        swap(vet[ini], vet[fim]);
    }
    if(vet[meio]->quantidade > vet[fim]->quantidade){
        swap(vet[meio], vet[fim]);
    }
    if(vet[ini]->quantidade > vet[meio]->quantidade){
        swap(vet[ini], vet[meio]);
    }
    swap(vet[meio], vet[fim]);
    return vet[fim];
}