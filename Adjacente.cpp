#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>
#include <cctype>
#include <iostream>
#include <locale.h>
//#include "Adjacente.h"
//#include "No.h"

Adjacente::Adjacente(No* p){
    no=p;
    id=no->getId();
    prox=NULL;
}

Adjacente::~Adjacente(){
}

void Adjacente::setProx(Adjacente *p){
    prox=p;
}

Adjacente* Adjacente::getProx(){
    return prox;
}

No* Adjacente::getNo(){
    return no;
}

int Adjacente::getId(){
    return id;
}

