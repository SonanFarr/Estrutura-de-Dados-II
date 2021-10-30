#include "../headers/review.h"

using namespace std;

Review::Review(){
  cout << "Passei no Construtor" << endl;
}

Review::~Review(){
  cout << "Destrutor" << endl;
}

void Review::processaReview(){
  cout << "Processa o arquivo com as reviews" << endl;
}


void Review::importaRegistros(){
  cout << "Importa os registros do arquivo" << endl;
}


void Review::acessaRegistro(int index){ // imprime na tela
  cout << "Acessa o termo (" << index << ") passado como parâmetro" << endl;
} 


void Review::testeImportacao(){
  int escolha;
  cout << endl;
  cout << "Digite:\n1 - Saída no console\n2 - Saída em arquivo" << endl;
  cin >> escolha;

  while(escolha != 1 && escolha != 2){
    cout << "Digite uma opção válida:\n1 - Saída em console\n2 - Saída no arquivo" << endl;
    cin >> escolha;
  }

  if(escolha == 1){
    cout << "Saída no console (n = 10)" << endl;
  } else {
    cout << "Saída em arquivo (n = 100)" << endl;
  }
}

void Review::teste(){
  processaReview();
  importaRegistros();
  acessaRegistro(1); // imprime na tela
  testeImportacao();
}

