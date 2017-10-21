#ifndef NO_H_INCLUDED
#define NO_H_INCLUDED
//#include "Lista.h"

class No{
private:
    No* proxId; //Lista encadeada que armazena os nós em ordem de id
    float peso;
    unsigned int id;
    unsigned int grau;
    unsigned int grauIn;
    unsigned int grauOut;
    bool digrafo;
    char auxBipartido;
    unsigned int componente;

public:
    Lista* lista;
    bool visitado;
    No(int i, bool d);
    ~No();
    int getId();
    void setId(int i);
    float getPeso();
    void setPeso(float p);
    int getGrau();
    void setGrau(int g);
    int getGrauIn();
    void setGrauIn(int grau);
    int getGrauOut();
    void setGrauOut(int grau);
    void insereAdj(No* n);
    void removeAdj(No* n);
    void setProx(No* n);
    char getAuxBipartido();
    void setAuxBipartido(char aux);
    No* getProx();
    int getComponente(){return componente;}
    void setComponente(int c){componente=c;}
};

#endif // NO_H_INCLUDED

