#ifndef VERSION_H
#define VERSION_H


#include <iostream>
#include "../headers/track.h"
#include "../headers/review.h"

using namespace std;

class Version{

    public:
        //? Constructors -------------------------------------
        Version();
        Version(Track *track);

        //? Destructor ---------------------------------------
        ~Version();

        //? Variáveis Públicas -------------------------------
        Version *prox;
        int quantidade;

        //? Funções Auxiliares -------------------------------
        Track *getTrack();
        void setTrack(Track *track);


    private:
        Track *track;
};

#endif