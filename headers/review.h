#ifndef REVIEW_H
#define REVIEW_H

#include <iostream>

class Review{
  public:
    Review();
    ~Review();

    // Ajeitar funcoes
    void processaReview();
    void importaRegistros();
    void acessaRegistro(int index); // imprime na tela
    void testeImportacao();

    void iniciar();
  private:
    
};

#endif
