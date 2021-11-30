#include <iostream>
#include <fstream>
#include "../headers/review.h"
#include "../headers/ordenacao.h"

using namespace std;

int main(int arqc, char *arqv[]) {

  // if(arqc != 2){
  //   cout << "ERRO: Argumentos inválidos ou ausentes." << endl;
  //   cout << "Esperado: ./<nome_programa> <diretório_arquivo>" << endl;

  //   return 1;
  // }

  // string dirArq(arqv[1]);

  // Review* r = new Review(dirArq);

  // r->verificaDir();
  
  // delete r; // don't remove this line (may cause memory leak)

  Ordenacao *ord = new Ordenacao(20);
  ord->selectionSort();
  
}