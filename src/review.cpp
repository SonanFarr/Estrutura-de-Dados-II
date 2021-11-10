#include <iostream>
#include <fstream>
#include "../headers/review.h"
#include "../headers/track.h"

using namespace std;

Review::Review(){
  
}

Review::Review(string dir){
  dirArq = dir;
}

Review::~Review(){

}

void Review::verificaDir(){
  cout << "Iniciando verificação do diretório:" << endl;
  cout << endl;

  string dirReview = dirArq + "tiktok_app_reviews.bin";

  ifstream reviewBin(dirReview, ios::in);

  if(!reviewBin.is_open()){
    cout << "O arquivo 'tiktok_app_reviews.bin' ainda não existe." << endl;
    cout << "Iniciando processamento e criação do arquivo binário:" << endl;

    processaReview();
  }
  else{
    // Implementar as funções para acessar o arquivo binário e realizar as operações.
  }
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


void Review::testeImportacao(ifstream *arqBin, ofstream *outFile){
  int escolha;
  int limit;
  int cont = 0;

  cout << "\nDigite:\n1 - Saída no console\n2 - Saída em arquivo" << endl;
  cin >> escolha;

  while(escolha != 1 && escolha != 2){
    cout << "Digite uma opção válida:\n1 - Saída em console\n2 - Saída no arquivo" << endl;
    cin >> escolha;
  }

  if(escolha == 1){
    cout << "Saída no console (n = 10)" << endl;
    limit = 10;
  } else {
    cout << "Saída em arquivo (n = 100)" << endl;
    limit = 100;
  }

  string id = "";
  string text = "";
  int votes = 0;
  string version = "";
  string date = "";

  Track *review = new Track(id, text, votes, version, date);

  while(cont < limit){

    

    review->setReview_id(id);
    review->setReview_text(text);
    review->setUpvotes(votes);
    review->setApp_version(version);
    review->setPosted_date(date);

    if(escolha == 1){
      
    }

    if(escolha == 2){

    }
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
      //testeImportacao(); Descomentar essa linha depois.
    } else {
      continua = false;
    }
  } while (continua);  

}

