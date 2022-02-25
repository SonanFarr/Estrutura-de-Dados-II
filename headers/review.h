#ifndef REVIEW_H
#define REVIEW_H

#include <iostream>
#include <string.h>
#include <cstring>
#include <vector>
#include "../headers/registro.h"

using namespace std;

//int limitIndex = 0;

class Review{
  public:
    Review();
    Review(string dir);
    ~Review();

    //? Funções de Processamento -----------------------------------------------
    void verificaDir();              // Função para verificar a existência do arquivo binário no diretório.
    void processaReview(int limit);
    
    //? Operações Principais ---------------------------------------------------
    void importaRegistros();
    void acessaRegistro(fstream &arq, int index);                                   // imprime na tela
    void acessaRegistroEscreveArquivo(fstream &arq, ofstream &outFile, int index);  // imprime no arquivo
    
    //? Módulo de Teste --------------------------------------------------------
    void testeImportacao(fstream &arqBin, int intervalo);

    //? Menu Iniciar -----------------------------------------------------------
    void iniciar(fstream &arq, int limit);
  

    //? Funções Auxiliares -----------------------------------------------------
    void escreveRegistro(fstream &arq, Registro registro, char text[]);
    void criaRegistro(fstream &arq, char id[], char text[], int votes, char version[], char date[]);
    Registro returnRegistro(fstream &arq, int index);

  private:
    string dirArq;       // String para armazenar o diretório do arquivo.
};

#endif
