#include "../headers/ordenacao.h"

Ordenacao::Ordenacao(){

}

Ordenacao::Ordenacao(int tamanho) {
  array = new int [tamanho];
  setTamanho(tamanho);
  criaAleatorio();
  imprimeArray();
}

Ordenacao::~Ordenacao(){
  delete array;
}

void Ordenacao::setTamanho(int tamanho) {
  this->tamanho = tamanho;
}

int Ordenacao::getTamanho() {
  return this->tamanho;
}

void Ordenacao::criaAleatorio() {
  for(int i = 0; i < getTamanho(); i++) {
    array[i] = rand() % getTamanho() * 2;
  }
}

void Ordenacao::imprimeArray() {
  for(int i = 0; i < getTamanho(); i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void Ordenacao::troca(int &a, int &b) {
  int aux = a;
  a = b;
  b = aux;
}

void Ordenacao::selectionSort() {
  for(int i = 0; i < this->tamanho-1; i++) {
    int min = i;
    for(int j = i + 1; j < this->tamanho; j++) {
      if(array[j] < array[min]) 
        min = j;
    }
    troca(array[i], array[min]);
    imprimeArray();
  }
}
