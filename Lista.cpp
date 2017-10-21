#include <iostream>
//#include "No.h"
//#include "Adjacente.h"
//#include "Lista.h"

using namespace std;

Lista::Lista()
{
    primeiro = NULL;
    ultimo = NULL;
}

Lista::~Lista()
{
    eliminaTodosAdj(); //deleta adjacentes instanciados;
    cout << "Lista deletado com sucesso!" << endl;
}

void Lista::insere(No* p)
{
    Adjacente *adj = new Adjacente(p);
    if(primeiro==NULL)
        primeiro = adj;
    else
        ultimo->setProx(adj);
    adj->setProx(NULL);
    ultimo=adj;
}

void Lista::elimina(int id)
{
    Adjacente* adj = retornaAdj(id);
    if(primeiro==NULL) //Lista vazia
        cout << "Lista vazia!" << endl;
    else if(adj==NULL) //No não está na lista
        cout << id << " nao eh adjacente do no." << endl;
    else
    {
        if(adj == primeiro)
        {
            if(adj == ultimo)
            {
                primeiro=NULL;
                ultimo=NULL;
            }
            else
                primeiro=adj->getProx();
        }
        else
        {
            Adjacente *ant;
            for(ant=primeiro; ant->getProx()!=adj; ant=ant->getProx()) //Acha o anterior ao adj;
            if(adj==ultimo)
            {
                ant->setProx(NULL);
                ultimo=ant;
            }
            else
                ant->setProx(adj->getProx());
        }
        delete adj;
        cout << "Adj deletado com sucesso!" << endl;
    }
}

void Lista::eliminaTodosAdj()
{
    Adjacente* p;
    for(p=primeiro;p!=NULL;p=p->getProx())
        elimina(p->getId());
}

Adjacente* Lista::retornaAdj(int id)
{
    Adjacente *p;
    for(p=primeiro; p!=NULL; p=p->getProx())
    {
        if(p->getId() == id)
            break;
    }
    return p;
}

Adjacente* Lista::getPrimeiro()
{
    return primeiro;
}

Adjacente* Lista::getUltimo()
{
    return ultimo;
}

void Lista::imprime()
{
    Adjacente *p;
    if(primeiro==NULL)
        cout << "Lista vazia!" << endl;
    else
    {
        for(p=primeiro; p!=NULL; p=p->getProx())
            cout << p->getId() << "\t";
        cout << endl;
    }
}

