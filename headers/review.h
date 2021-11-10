#ifndef REVIEW_H
#define REVIEW_H

#include <iostream>

using namespace std;

class Review{
  public:
    Review();
    Review(string dir);
    ~Review();

    void verificaDir();  // Função para verificar a existência do arquivo binário no diretório.

    // Ajeitar funcoes
    void processaReview();
    void importaRegistros();
    void acessaRegistro(int index); // imprime na tela
    void testeImportacao(ifstream *arqBin, ofstream *outFile);

    void iniciar();
  
  private:
    string dirArq;       // String para armazenar o diretório do arquivo.
};

#endif
