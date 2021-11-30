#ifndef ORDENACAO_H
#define ORDENACAO_H

#include <iostream>

using namespace std;

class Ordenacao{
  public:
    Ordenacao();
    Ordenacao(int tamanho);
    ~Ordenacao();

    // Funções importantes
    void criaAleatorio();
    void imprimeArray();
    
    // Função Troca
    void troca(int &a, int &b);

    // Getters e Setters
    void setTamanho(int tamanho);
    int getTamanho();

    // Ordenacoes
    void selectionSort();
  private:
    int *array;
    int tamanho;

};

#endif