#ifndef REGISTRO_H
#define REGISTRO_H

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <sstream>
#include <cstring>
#include <ctime>

using namespace std;

class Registro{
  public:
    Registro();
    ~Registro();

    char review_id[100];     // String para armazenar o id do comentário.
    char review_text[2000];  // String para armazenar o comentário.
    int upvotes;             // Inteiro para armazenar os votos favoráveis.
    char app_version[7];     // String para armazenar a versão do app;
    char posted_date[20];    // String para armazenar a data e hora da postagem.

  private:


};

#endif