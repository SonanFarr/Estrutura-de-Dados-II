#include <iostream>
#include "../headers/track.h"
#include "../headers/review.h"
#include "../headers/version.h"

using namespace std;

//? Constructors --------------------------------------------------------------
Version::Version(){
    prox = nullptr;
    quantidade = 1;
}

Version::Version(Track *track){
    this->track = track;
    prox = nullptr;
    quantidade = 1;
}

//? Destructor ----------------------------------------------------------------
Version::~Version(){
    track = nullptr;
    prox = nullptr;
    quantidade = NULL;

    delete track, prox, quantidade;
}

//? Funções Auxiliares --------------------------------------------------------
Track *Version::getTrack(){
    return track;
}

void Version::setTrack(Track *track){
    this->track = track;
}