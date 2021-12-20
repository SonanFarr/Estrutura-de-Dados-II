//Encontra-se as decalrações declara o algoritmo e suas funções
#ifndef CESTO_H_INCLUDED
#define CESTO_H_INCLUDED
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class cesto
{
private:
    int profundidadeLocal;
    int tamanhoUtilizado;
    int tamTotal;
    vector<string> valorDoCesto;

public:
    cesto(int tamanhoMax);
    ~cesto();
    void LimpaCesto();
    void Remove(string valor, int ProfundidadeGlobal);
    void Remove(int posicao, int ProfundidadeGlobal);
    bool Insert(string valorDoCesto, int ProfundidadeGlobal);
    void SetLocalTamMax(int nova_profundidade_local);
    void RecalculaTamanhoMax(string valor, int ProfundidadeGlobal);
    int GetLocal(int bitsImportantes);
    bool Completo();
    int GetTamanhoMax();
    int GetTamanhoUtilizado();
    int GetElementos(string chave);
    int GetTamanhoMax();
    string GetElemento(int posicao);
    int Encontrar(string valor);
    int Search(string chaveHash);
    void ImprimeCesto();
};
#endif
