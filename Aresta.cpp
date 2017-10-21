#include <iostream>
//#include "Aresta.h"
//#include "No.h"

Aresta::Aresta(No* a, No* b, bool d){
    noAnt=a;
    noProx=b;
    digrafo=d;
    if(!digrafo)
        noProx->insereAdj(noAnt);
    noAnt->insereAdj(noProx);
}

Aresta::~Aresta(){
    if(!digrafo)
        noProx->removeAdj(noAnt);
    noAnt->removeAdj(noProx);
}

float Aresta::getPeso(){
    return peso;
}

void Aresta::setPeso(float p){
    peso=p;
}

void Aresta::setProx(Aresta* a){
    prox=a;
}

Aresta* Aresta::getProx(){
    return prox;
}

No* Aresta::getNoAnt(){
    return noAnt;
}

No* Aresta::getNoProx(){
    return noProx;
}

void Aresta::imprime(){
    cout << " ( " << noAnt->getId() << " , " << noProx->getId() << " ) " << endl;
}

