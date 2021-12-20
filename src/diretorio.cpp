#include <iostream>
#include <chrono>
#include <cstdlib>
#include <string>
#include <vector>
#include <math.h>
#include "../headers/track.h"
#include "../headers/review.h"
#include "../headers/diretorio.h"
#include "../headers/cesto.h"

using namespace std;
using namespace std::chrono;
/**
//Diretorio::Diretorio(int numBits, int tamanhoMaxCesto){
    //this->numBits = numBits;
    //this->tamanhoMaxCesto = tamanhoMaxCesto;
    //this->numChaves = 0;
    //this->cesto = 0;
    //this->global = 2;

    //Cesto *primeiro = new Cesto(tamanhoMaxCesto);
    //this->cesto++;
    //for(int i=0; i<pow(2, this->global); i++)
        //this->cestos.push_back(primeiro);
//}

Diretorio::~Diretorio(){
    this->cestos.~vector();
    delete &this->global;
    delete &this->numBits;
    delete &this->tamanhoMaxCesto;
}

string Diretorio::hash(int valor, int numBits){
    string valorHash;
    for(int i=numBits-1; i>=0; i--){
        int k = valor >> i;
        if(k&1)
            valorHash.push_back('1');
        else
            valorHash.push_back('0');
    }
    return valorHash;
}

//void Diretorio::inserir(int valor){
    //string valorHash = this->hash(valor, this->numBits);
    //string bitSignificante = valorHash.substr(0, this->global);
    //int valorIndice = this->binarioDecimal(bitSignificante);
    //if(!this->cestos[valorIndice]->Completo()){
        //this->cestos[valorIndice]->inserir(valorHash, this->global);
        //this->numChaves++;
    //}
    //else if(this->cestos[valorIndice]->Completo && this->global > this->cestos[valorIndice]->GetLocal())
        //this->cestos[valorIndice] = dividirCesto(valorHash);
    //else if(this->global < this->numBits){
        //this->duplicarDiretorio();
        //bitSignificativo = valorHash.substr(0, this->global);
        //int posicao = this->binarioDecimal(bitSignificativo);
        //this->cestos[posicao] = dividirCesto(valorHash);
    //}
//}

//bool Diretorio::encontrar(int valor){
    //string valorHash = this->hash(valor, this->numBits);
    //string bitSignificante = valorHash.substr(0, this->global);
    //int posicao = this->binarioDecimal(bitSignificante);
    //if(this->cestos[posicao] != NULL){
        //if(this->cestos[posicao]->encontrar(valorHash) != -1)
            //return true;
    //}
    //return false;
//} 

void Diretorio::duplicarDiretorio(){
    //vector<Cesto*> cestoCopiado = this->cestos;
    for(int i=pow(2, this->global); i<pow(2, this->global+1); i++)
        this->cestos.push_back(NULL);
    this->global++;
    int j = 0;
    for(int i=0; i<pow(2, this->global); i+=2){
        //this->cestos[i] = cestoCopiado[j];
        //this->cestos[i+1] = cestoCopiado[j];
        j++;
    }
    //cestoCopiado.LimparCesto();
    //cestoCopiado.shrink_to_fit();
}

//Cesto* Diretorio::dividirCesto(string chave){
    //Cesto* novoCesto = new Cesto(this->tamanhoMaxCesto);
    //this->cesto++;
    //string bitSignificante = chave.substr(0, this->global);
    //int posicaoChave = this->binarioDecimal(bitSignificante);
    //novoCesto->insere(chave, global);
    //this->numChaves++;
    //vector<string> valoresInseridos;
    //valoresInseridos.reserve(this->tamanhoMaxCesto);
    //for(int i=0; i<this->cestos[posicaoChave]->GetTamanhoUtilizado(), i++){
        //if(this->cestos[posicaoChave]->GetElementos(i).substr(0, this->global) == bitSignificante){
            //novoCesto->insere(this->cestos[posicaoChave]->GetElementos(i), this->global);
            //valoresInseridos.push_back(this->cestos[posicaoChave]->GetElementos(i));
        //}
    //}
    //for(string valor : ValoresInseridos){
        //this->cestos[posicaoChave]->remove(valor, this->global);
    //}
    //return novoCesto;
//}

int Diretorio::GetNumDeCestos(){
    return this->cesto;
}

int Diretorio::GetNumDeChaves(){
    return this->numChaves;
}

int Diretorio::binarioDecimal(int n){
    int decimal = 0;
    int i = 0;
    int r;
    while(n!=0){
        r = n % 10;
        n /= 10;
        decimal += r * pow(2, i);
        i++; 
    }
    return decimal;
}
*/