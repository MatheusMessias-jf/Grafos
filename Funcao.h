#include <iostream>
//#include "No.h"
//#include "Adjacente.h"
//#include "Lista.h"

class Grafo;

class Funcao{
public:
    Funcao();
    ~Funcao();
    int exibeMenu(Grafo* grafo);
    void exibeSubMenu(Grafo* grafo);
    void exibeSubMenu2(Grafo* grafo);
    void chamaFuncaoEscolhida(Grafo* grafo, int opMenu);
    Grafo* leituraTxt(/*char* arquivo[]*/);
    void escritaTxt(int i, int j, int peso);
    float excentricidade();

};



