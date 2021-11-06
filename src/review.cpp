#include "../headers/review.h"

using namespace std;

Review::Review(){

}

Review::~Review(){

}

void Review::processaReview(){
  cout << "Processa o arquivo com as reviews" << endl;
}


void Review::importaRegistros(){
  cout << "Importa os registros do arquivo" << endl;
}


void Review::acessaRegistro(int index){ // imprime na tela
  cout << "Acessa o termo (" << index << ") passado como parâmetro\n" << endl;
} 


void Review::testeImportacao(){
  int escolha;
  cout << "\nDigite:\n1 - Saída no console\n2 - Saída em arquivo" << endl;
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

void Review::iniciar(){
  cout << "-------------BEM VINDO-------------\n" << endl;

  cout << "As reviews serão processadas e importadas\n" << endl;
  processaReview();
  importaRegistros();

  cout << "As reviews já foram processadas e importadas" << endl;

  bool continua = true;

  do{
    cout << "Digite uma das opções abaixo: " << endl;
    cout << "1 - Acessar Registro" << endl;
    cout << "2 - Testar Importação" << endl;
    cout << "3 - Sair do programa" << endl;
    
    int escolha;
    cin >> escolha;

    while(escolha < 1 || escolha > 3){
      cout << "Digite uma opção válida:\n1 - Acessar Registro\n2 - Testar Importação\n3 - Sair do programa" << endl;
      cin >> escolha;
    }

    if(escolha == 1){
      int i;
      cout << "\nDigite o índice do parâmetro" << endl;
      cin >> i;
      acessaRegistro(i); // imprime na tela
    } else if (escolha == 2) {
      testeImportacao();
    } else {
      continua = false;
    }
  } while (continua);  

}

