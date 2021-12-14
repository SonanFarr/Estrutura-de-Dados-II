
#include <iostream>
#include <chrono>
#include <cstdlib>
#include <string>
#include <vector>
#include <math.h>
#include "../headers/track.h"
#include "../headers/review.h"
#include "../headers/ordenacao.h"

using namespace std;
using namespace std::chrono;

using namespace std;

//? Variaveis Auxiliares ---------------------------------------------------------------------------------------
  long long comparacoes = 0;
  long long trocas = 0;

//? Constructor ------------------------------------------------------------------------------------------------
Ordenacao::Ordenacao(){

}

//? Destructor -------------------------------------------------------------------------------------------------
Ordenacao::~Ordenacao(){

}

//? Funções Auxiliares Gerais ----------------------------------------------------------------------------------
/**
 * @brief    Função auxiliar para trocar a posição entre dois elementos.
 * 
 * @param a  Elemento a.
 * @param b  Elemento b.
 */
void Ordenacao::troca(Track &a, Track &b) {
  Track aux = a;
  a = b;
  b = aux;
}

/**
 * @brief         Função para criar um vetor com n tracks aleatórias.
 * 
 * @param arq     Arquivo do qual será lido os registros.
 * @param n       Tamanho do vetor a ser criado.
 * @return Track  Vetor de tracks criado.
 */
Track *Ordenacao::criaVetorTrack(fstream &arq, int n){
  
  if(!arq.is_open()){
    cout << "ERRO: Arquivo não foi aberto corretamente." << endl;

    return NULL;
  }
  else{

    Track *vet = new Track[n];
    Review r;

    srand(time(NULL));

    int limit = sizeof(arq)/sizeof(Track);
    int indice;

    for(int i=0; i<n; i++){
      indice = rand()%55000;
      vet[i] = r.returnTrack(arq, indice);
    }

    return vet;
  }
}

//void criaAleatorio() {
  //for(int i = 0; i < getTamanho(); i++) {
    //array[i] = rand() % getTamanho() * 2;
  //}
//}

//void imprimeArray() {
  //for(int i = 0; i < getTamanho(); i++) {
    //cout << array[i].upvotes << " ";
  //}
    //cout << endl;
//}


//? Funções Auxiliares HeapSort --------------------------------------------------------------------------------
/**
 * @brief    Função auxiliar para manipulação da heap.
 * 
 * @param v  Vetor de tracks.
 * @param i  Índice auxiliar.
 * @param n  Tamanho do vetor de tracks.
 */
void Ordenacao::heapify(Track *vet, int i, int n){

    while(i < n)
    {
        int filho = 2*i + 1;
        if(filho < n)
        {
            if(filho+1 < n && vet[filho+1].upvotes > vet[filho].upvotes){
                filho++;
                comparacoes = comparacoes + 1;
            }
            
            if(vet[filho].upvotes > vet[i].upvotes){
                troca(vet[i], vet[filho]);
                trocas = trocas + 1;
                comparacoes = comparacoes + 1;
            }
        }
        i = filho;
    }
}

/**
 * @brief    Função auxiliar para criação da árvore heap.
 * 
 * @param v  Vetor de tracks.
 * @param n  Tamanho do vetor de tracks.
 */
void Ordenacao::constroiHeap(Track *vet, int n){
    
    for(int i = n/2-1; i >= 0; i--){
        heapify(vet, i, n-1);
    }
}

/**
 * @brief    Função auxiliar para ordenação da heap. 
 * 
 * @param v  Vetor de tracks.
 * @param n  Tamanho do vetor de tracks.
 */
void Ordenacao::heapSortRec(Track *vet, int n){
    
    constroiHeap(vet, n);
    while(n > 0)
    {
        troca(vet[0], vet[n-1]);
        trocas = trocas +1;
        heapify(vet, 0, n-1);
        n--;
    }
}

//? Algorítimos de Ordenação ------------------------------------------------------------------------------------

//void selectionSort() {
  //for(int i = 0; i < this->tamanho-1; i++) {
    //int min = i;
    //for(int j = i + 1; j < this->tamanho; j++) {
      //if(array[j].upvotes < array[min].upvotes) 
        //min = j;
    //}
    //troca(array[i], array[min]); Necessário fazer a adaptação para a ordenação das tracks.
    //imprimeArray();
  //}
//}

/**
 * @brief    Função principal para o algorítimo HeapSort.
 * 
 * @param v  Vetor de tracks que será ordenado.
 * @param n  Tamanho do vetor a ser ordenado.
 */
void Ordenacao::heapSort(ifstream &arqDat, ofstream &outfile, fstream &arq){
 
  outfile << "Medindo desempenho do algorítimo HeapSort: \n" << endl;
  cout << "Medindo desempenho do algorítimo HeapSort: \n" << endl;

  int m = 3;
  long long time;
  long long somaTime = 0;
  long long somaComp = 0;
  long long somaMovi = 0;

  if(!outfile.is_open() || !arqDat.is_open()){
    cout << "ERRO: Algo deu errado com a abertura de um dos arquivos." << endl;
  }
  else{
    string line;
    int i = 0;

    while(i<2){
      getline(arqDat, line, '\n');
      int n = stoi(line);

      for(int i=0; i<m; i++){
        Track *vet = criaVetorTrack(arq, n);

        auto inicio = chrono::high_resolution_clock::now();

        heapSortRec(vet, n);

        auto final = chrono::high_resolution_clock::now() - inicio;
        
        time = chrono::duration_cast<chrono::microseconds>(final).count();

        somaTime = somaTime + time;
        somaComp = somaComp + comparacoes;
        somaMovi = somaMovi + trocas;

        comparacoes = 0;
        trocas = 0;

        delete[] vet;
      }

      outfile << "N = " << n << " registros: \n" << endl;
      outfile << "Média de Tempo: " << (somaTime/m)/ 1000000.0 << "\n";
      outfile << "Média de Comparações: " << somaComp/m << "\n";
      outfile << "Média de Movimentações: " << somaMovi/m << "\n";
      outfile << "\n";

      somaTime = 0;
      somaComp = 0;
      somaMovi = 0;

      i++;
    }
  }
  arqDat.close();
  outfile.close();
}

//? Função de medida de desempenho ------------------------------------------------------------------------------

/**
 * @brief      Função principal para teste de desempenho dos algorítimos de ordenação.
 * 
 * @param arq  Arquivo binário para leitura dos registros.
 * @param n    Tamanho do vetor a ser criado. 
 */
void Ordenacao::medeDesempenho(string dir, fstream &arq, int n){

  string dirArqDat = dir + "/input.dat";
  string dirOutfile = dir + "/outfile.txt";

  ifstream arqDat(dirArqDat, ios::in);
  ofstream outfile(dirOutfile, ios::app);

  heapSort(arqDat, outfile, arq);

}
