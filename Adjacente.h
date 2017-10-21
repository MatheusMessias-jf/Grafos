#ifndef ADJACENTE_H_INCLUDED
#define ADJACENTE_H_INCLUDED
//#include "No.h"

class No;
class Adjacente{
    private:
        int id;
        No* no;
        Adjacente *prox;

    public:
        Adjacente(No *p);
        ~Adjacente();
        void setProx(Adjacente *p);
        Adjacente* getProx();
        No* getNo();
        int getId();
};

#endif // ADJACENTE_H_INCLUDED

