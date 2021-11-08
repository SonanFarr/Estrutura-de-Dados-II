#include <iostream>
#include "../headers/review.h"

using namespace std;

int main(int arqc, char *arqv[]) {

  if(arqc != 2){
    cout << "ERRO: Argumentos inválidos ou ausentes." << endl;
    cout << "Esperado: ./<nome_programa> <diretório_arquivo>" << endl;

    return 1;
  }

  string dirArq(arqv[1]);

  Review* r = new Review(dirArq);

  r->iniciar();
  
  delete r; // don't remove this line (may cause memory leak)
}