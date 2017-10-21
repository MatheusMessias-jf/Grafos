#include <iostream>
//#include "No.h"
//#include "Lista.h"

using namespace std;

No::No(int i, bool d){
    id=i;
    lista= new Lista();
    grau=0;
    grauIn=0;
    grauOut=0;
    peso=0;
    visitado=NULL;
    proxId=NULL;
    digrafo=d;
}

No::~No(){
    delete lista;
    cout << "No deletado com sucesso!" << endl;
}

int No::getId(){
    return id;
}

void No::setId(int i){
    id=i;
}

float No::getPeso(){
    return peso;
}

void No::setPeso(float p){
    peso=p;
}

int No::getGrau(){
    return grau;
}

void No::setGrau(int g){
    grau = g;
}

int No::getGrauIn(){
    return grauIn;
}

void No::setGrauIn(int grau){
    grauIn = grau;
}

int No::getGrauOut(){
    return grauOut;
}

void No::setGrauOut(int grau){
    grauOut = grau;
}

void No::insereAdj(No* n){
    lista->insere(n);
    if(digrafo)
    {
        grauOut++;
        n->setGrauIn(n->getGrauIn()+1);
    }
    else
        grau++;
}

void No::removeAdj(No* n){
    lista->elimina(n->getId());
    if(digrafo)
    {
        grauOut--;
        n->setGrauIn(n->getGrauIn()+1);
    }
    else
        grau--;
}

void No::setProx(No *n){
    proxId=n;
}

No* No::getProx(){
    return proxId;
}

char No::getAuxBipartido(){
    return auxBipartido;
}

void No::setAuxBipartido(char aux){
    auxBipartido=aux;
}

