#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

//#include "Adjacente.h"
//#include "No.h"

class No;
class Adjacente;

class Lista{
private:
    Adjacente* primeiro;
    Adjacente* ultimo;

public:
    Lista();
    ~Lista();
    void insere(No*p);
    void elimina(int id);
    void eliminaTodosAdj();
    Adjacente* getPrimeiro();
    Adjacente* getUltimo();
    Adjacente* retornaAdj(int id); //Antigo busca(), mudei o nome por achar confuso;
    void imprime();
};

#endif // LISTA_H_INCLUDED

