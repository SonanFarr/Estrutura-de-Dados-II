#ifndef TRACK_H
#define TRACK_H

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <sstream>
#include <cstring>
#include <ctime>

using namespace std;

class Track{
  public:
    Track();
    ~Track();

    char review_id[100];    // String para armazenar o id do comentário.
    char review_text[2000];  // String para armazenar o comentário.
    char upvotes[5];      // String para armazenar os votos favoráveis.
    char app_version[7];  // String para armazenar a versão do app;
    char posted_date[20];  // String para armazenar a data e hora da postagem.

  private:


};

#endif