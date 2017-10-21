#ifndef ARESTA_H_INCLUDED
#define ARESTA_H_INCLUDED
#include <iostream>
//#include "No.h"

using namespace std;

class Aresta{
private:
    float peso;
    No *noAnt;
    No *noProx;
    Aresta* prox; //Por causa da lista encadeada;
    bool digrafo;

public:
    Aresta(No* a, No* b, bool d);
    ~Aresta();
    void setPeso(float p);
    float getPeso();
    void setProx(Aresta* a);
    Aresta* getProx();
    No* getNoAnt();
    No* getNoProx();
    void imprime();
};

#endif // ARESTA_H_INCLUDED

