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
    void testeImportacao();

    void iniciar();
  
  private:
    string dirArq;       // String para armazenar o diretório do arquivo.

    string review_id;    // String para armazenar o id do comentário.
    string review_text;  // String para armazenar o comentário.
    int upvotes;         // String para armazenar os votos favoráveis.
    string app_version;  // String para armazenar a versão do app;
    string posted_date;  // String para armazenar a data e hora da postagem.
};

#endif
