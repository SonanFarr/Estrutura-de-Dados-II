//Onde é desenvolvido o algoritmo
#include "./cesto.h"
#include <list>
#include <algorithm>

/**

cesto::cesto(int tamUtilizado)
{
    this->tamTotal = 0;
    this->profundidadeLocal = 0;
    this->tamanhoUtilizado = tamanhoUtilizado;
}
string cesto::GetElemento(int posicao)
{
    return this->valorDoCesto[posicao];
}
int cesto::GetTamanhoUtilizado()
{
    return this->tamanhoUtilizado;
}
void cesto::SetLocalTamMax(int nova_profundidade_local)
{
    this->profundidadeLocal = nova_profundidade_local;
}

bool cesto::Insert(string profundidadeLocal, int ProfundidadeGlobal)
{
    //Verifica se é posicaosivel inserir o valor no balde
    if (this->tamanhoUtilizado < this->TamTotal)
    {
        this->profundidadeLocal.push_back(profundidadeLocal);
        //Vai verificar se a profundidade precisa ser alterada
        this->RecalculaTamanhoMax(profundidadeLocal, ProfundidadeGlobal);
        this->tamanhoUtilizado++;

        return true;
    }

    return false;
}

void cesto::RecalculaTamanhoMax(string valor, int ProfundidadeGlobal)
{

    string bits_significativos = valor.substr(0, ProfundidadeGlobal);
    //Ocorrência dos bits significativos no meu vetor
    int ValorOcorrencia = 0;
    int BitsIguais;
    this->profundidadeLocal = 0;

    for (int k = 0; k < ProfundidadeGlobal; k++)
    {
        BitsIguais = 0;
        for (int l = 0; l < this->GetTamanhoUtilizado(); l++)
        {
            if (significant_bits.at(k) == this->valorDoCesto[l].at(k))
            {
                BitsIguais++;
            }
        }
        if (BitsIguais == this->GetTamanhoUtilizado())
            this->profundidadeLocal++;
    }
}

void cesto::ImprimeCesto()
{
    cout << "Cesto " << endl;
    cout << "Valores : ";
    for (string valor : this->profundidadeLocal)
    {
        cout << valor + ",";
    }
    cout << endl;
}

int cesto::Encontrar(string valores)
{
    int j = 0;
    for (string valorAtual : this->profundidadeLocal)
    {
        if (valor == valorAtual)
            return j;

        j++;
    }
    //Se não achar o valor retorrna -1
    return -1;
}

void cesto::LimpaCesto()
{
    this->profundidadeLocal.LimpaCesto();
    this->SetLocalDepth(0);
}

bool cesto::Completo()
{
    return this->tamanhoUtilizado == this->TamTotal;
}

void cesto::Remove(int posicao, int ProfundidadeGlobal)
{
    this->profundidadeLocal.erase(this->profundidadeLocal.begin() + posicao);
    this->tamanhoUtilizado--;

    int j = 0;
    //Conserta a profundidade local do balde
    for (string valor : this->profundidadeLocal)
    {
        //Apago o valor a ser comparado na recalculação , pois se ele existir no vetor ele vai comparar o elemento a si mesmo
        this->profundidadeLocal.erase(this->profundidadeLocal.begin() + j);
        this->tamanhoUtilizado--;
        RecalculaTamanhoMax(valor, ProfundidadeGlobal);
        this->profundidadeLocal.push_back(valor);
        this->tamanhoUtilizado++;
        j++;
    }
}

void cesto::Remove(string valor, int ProfundidadeGlobal)
{
    int posicao = this->Encontrar(valor);
    if (posicao != -1)
    {
        this->profundidadeLocal.erase(this->profundidadeLocal.begin() + posicao);
        this->tamanhoUtilizado--;
        int j = 0;
        //Recalcula a profundidade local do balde
        for (string valor : this->profundidadeLocal)
        {
            this->profundidadeLocal.erase(this->profundidadeLocal.begin() + j);
            this->tamanhoUtilizado--;
            RecalculaTamanhoMax(valor, ProfundidadeGlobal);
            this->profundidadeLocal.push_back(valor);
            this->tamanhoUtilizado++;
            j++;
        }
    }
}

cesto::~cesto()
{
    this->profundidadeLocal.~vector();
    //definida no .h
}
*/
