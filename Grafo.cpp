#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>
#include <cctype>
#include <iostream>
#include <locale.h>
#include <vector>
//#include "Grafo.h"
//#include "Aresta.h"
//#include "No.h"
//#include "Adjacente.h"

using namespace std;

Grafo::Grafo()
{
   setlocale(LC_ALL, "Portuguese");
    ordem = 0;
    primeiraAresta = NULL;
    primeiroNo = NULL;
    ultimaAresta = NULL;
    ultimoNo = NULL;
    ponderado = 1;
    digrafo=0;
    m=0;

    /*cout << "O grafo eh digrafo? \n(1) Sim ou (0) Nao" << endl;
    int resposta;
    cin >> resposta;
    (resposta==1)?digrafo=true:digrafo=false;
    system("cls");*/
}

Grafo::~Grafo()
{
}

void Grafo::incluiNo(int id)
{
    float peso;
    ordem++;
    No* n = new No(id,digrafo);
    /*if(ponderado)
    {
        cout << "Digite o peso:";
        cin >> peso;
        n->setPeso(peso);
    }*/

    if(vazio())
    {
        primeiroNo = n;
        ultimoNo = n;
    }
    else
    {
        ultimoNo->setProx(n);
        ultimoNo=n;
    }
    n->setProx(NULL);
}

bool Grafo::vazio() //Verifica se o grafo é vazio
{
    return primeiroNo==NULL;
}

void Grafo::incluiAresta(int noI, int noJ, float peso)
{
    if(retornaNoById(noI)==NULL)
        cout << "Nó com ID " << noI << " não existe." << endl;
    else if(retornaNoById(noJ)==NULL)
        cout << "Nó com ID " << noJ << " não existe." << endl;
    else
    {
        Aresta* a = new Aresta(retornaNoById(noI),retornaNoById(noJ),digrafo);
        m++;
        a->setPeso(peso);
        a->setProx(NULL);
        if(primeiraAresta==NULL)
            primeiraAresta=a;
        else
            ultimaAresta->setProx(a);
        ultimaAresta=a;
    }
}

void Grafo::excluiNo(int id)
{
    cout << "Excluindo No." << endl;
    if(vazio())
        cout << "Grafo vazio!" << endl;
    else
    {
        No* no = retornaNoById(id);
        if(no==NULL)
            cout << "No nao existe!" << endl;
        else
        {
            if(infoTrivial())
            {
                primeiroNo=NULL; //Ao excluir o primeiroNo nó, primeiroNo=NULL;
                ultimoNo=NULL; //O primeiroNo também é o último nó;
            }
            else
            {
                if(no==primeiroNo)
                    primeiroNo=no->getProx();
                else
                {
                    No *noAnt=retornaNoById(id-1);
                    noAnt->setProx(no->getProx());   //Reorganiza lista encadeada de nós tirando o nó q da mesma
                }
                //Exclui arestas relacionadas ao nó que será excluido
                Adjacente *adj;
                for(adj=no->lista->getPrimeiro(); adj!=NULL; adj=adj->getProx())
                    excluiAresta(id,adj->getId());
                delete no; //Chama destrutor do no;
                ordem--;
                cout << "No excluido com sucesso." << endl;
            }
        }
    }
}

No* Grafo::retornaNoById(int id) //Busca nó dado o ID
{
    No *p=primeiroNo;
    for(int i=1; i<id; i++)
        p=p->getProx();
    return p;
}

Aresta* Grafo::procuraAresta(No* i, No* j)
{
    Aresta *a;
    for(a=primeiraAresta; a!=NULL; a=a->getProx())
    {
        if(digrafo)
        {
            if(a->getNoAnt()== i && a->getNoProx()==j)
                break;
        }
        else
        {
            if((a->getNoAnt()== i && a->getNoProx()==j) || (a->getNoAnt()== j && a->getNoProx()==i))
                break;
        }

    }
    return a;
}

Aresta* Grafo::procuraArestaMultigrafo(No* i, No* j)
{
    Aresta *a;
    for(a=primeiraAresta; a!=NULL; a=a->getProx())
    {
        if(digrafo)
        {
            if(a->getNoAnt()== i && a->getNoProx()==j)
                break;
        }
        else
        {
            if(a->getNoAnt()== i && a->getNoProx()==j)
                break;
        }

    }
    return a;
}

void Grafo::excluiAresta(int i, int j)
{
    cout << "Excluindo aresta entre " << i << " e " << j << "." << endl;
    No* noI = retornaNoById(i);
    No* noJ = retornaNoById(j);
    if(noI== NULL)
        cout << "Nó " << i << " não existe. \nFalha em excluir aresta." << endl;
    else if(noJ== NULL)
        cout << "Nó " << j << " não existe. \nFalha em excluir aresta." << endl;
    else
    {
        Aresta *a = procuraAresta(noI,noJ);
        if(a==NULL)
            cout << "Nao existe aresta entre esses dois nos." << endl;
        else
        {
            delete a;
            m--;
            cout << "Aresta excluida com sucesso." << endl;
        }
    }
}

int Grafo::retornaGrauNo(int id)
{
    No *n = retornaNoById(id);
    if(n!=NULL)
        return n->getGrau();
    else
    {
        cout << "Nó não existe!" << endl;
        exit(0);
    }
}

int Grafo::retornaGrauInNo(int id)
{
    No *n = retornaNoById(id);
    if(n!=NULL)
        return n->getGrauIn();
    else
    {
        cout << "Nó não existe!" << endl;
        exit(0);
    }
}

int Grafo::retornaGrauOutNo(int id)
{
    No *n = retornaNoById(id);
    if(n!=NULL)
        return n->getGrauOut();
    else
    {
        cout << "Nó não existe!" << endl;
        exit(0);
    }
}

bool Grafo::verificaKRegularidade(int k)
{
    No* n;
    for(n=primeiroNo; n->getProx()!=NULL; n=n->getProx()) //Verifica se todos os nós tem o mesmo grau
    {
        if(n->getGrau()!=k) //Se algum não for =k, o grafo não é k-regular;
            return false;
    }
    return true;
}

int Grafo::infoOrdem() // Informa a ordem do grafo (número de nós);
{
    return ordem;
}

bool Grafo::infoTrivial() // Informar se o grafo é trivial;
{
    //G é trivial se sua ordem for 1
    return (infoOrdem()==1);
}

bool Grafo::infoNull() //Informar se o grafo é nulo;
{
    //Grafo será nulo quando não houver arestas
    return primeiraAresta==NULL;
}

void Grafo::vizinhancaAberta(int id) //Mostrar a vizinhança aberta de um dado nó informado pelo usuário;
{
    No* n = retornaNoById(id);
    //Vizinhança aberta: Lista de adjacentes
    if(n!=NULL)
    {
        cout << "Vizinhança aberta do no " << id << ": ";
        n->lista->imprime();
    }
    else
        cout << "Nó não existe!" << endl;
}

void Grafo::vizinhancaFechada(int id) //Mostrar a vizinhança fechada de um dado nó informado pelo usuário;
{
    No* n = retornaNoById(id);
    //Vizinhança aberta: Lista de adjacentes + o próprio nó
    if(n!=NULL)
    {
        cout << "Vizinhança fechada do no " << id << ": ";
        cout << n->getId() << "\t";
        n->lista->imprime();
    }
    else
        cout << "Nó não existe!" << endl;
}

void Grafo::imprimeNoAdjacentes()
{
    cout << "No: | Lista de Adjacentes:"  << endl;
    for(No* n=primeiroNo; n!=NULL; n=n->getProx())
    {
        cout << n->getId() << ": ";
        for(Adjacente* adj1=n->lista->getPrimeiro(); adj1!=NULL; adj1=adj1->getProx())
        {
            cout << adj1->getId() << ", ";
        }
        cout << endl;
    }
}

bool Grafo::verificaMultigrafo()
{
    bool var;
    for(No* n=primeiroNo; n!=NULL; n=n->getProx())
    {
        for(Adjacente* adj1=n->lista->getPrimeiro(); adj1!=NULL; adj1=adj1->getProx())
        {
            if(adj1->getNo()==n)
                return false;
            for(Adjacente* adj2=n->lista->getPrimeiro(); adj2!=NULL; adj2=adj2->getProx())
            {
                if(adj1==adj2)
                {
                    var = true;
                }
            }
        }
    }
    if(var)
        return true;
    else
        return false;
}

bool Grafo::verificaCompleto() //É completo se tiver um par de aresta para todo nó i, j;
{
    for(No *p=primeiroNo; p!=NULL; p=p->getProx())
    {
        for(No *q=primeiroNo; q!=NULL; q=q->getProx())
        {
            if(p!=q)
            {
                if(procuraAresta(p,q)==NULL)
                    return false;
            }
        }
    }
    return true;
}

void Grafo::buscaProfudidade()
{
    componentes=0;
    for(No* n=primeiroNo; n!=NULL; n=n->getProx()) ///marcar todos como visitados
        n->visitado=0;
    bipartido=true;

    for(No* n=primeiroNo; n!=NULL; n=n->getProx())
    {
        if(n->visitado==0)
        {
            componentes++;
            prof(n,"a",componentes);
        }
    }
}

void Grafo::prof(No* n, char* auxB, int comp)
{
    n->setComponente(comp);
    n->visitado=true;
    n->setAuxBipartido(*auxB);
    for(Adjacente* adj=n->lista->getPrimeiro(); adj!=NULL; adj=adj->getProx())
    {
        if(adj->getNo()->getAuxBipartido()==*auxB)
            bipartido=false;
        if(adj->getNo()->visitado==0)
        {
            if(auxB=="a")
                prof(adj->getNo(),"b",comp);
            else
                prof(adj->getNo(),"a",comp);
        }
    }
}

bool Grafo::verificaBipartido()
{
    buscaProfudidade();
    return bipartido;
}

float Grafo::caminhoMin(int i, int j) ///ARRUMAR (completar) FUNÇÃO
{
//m) Dados dois vértices informados pelo usuário, mostrar
//o caminho mínimo e seu custo entre esses vértices (utilizar o
//algoritmo de Dijkstra ou de Floyd, conforme o usuário solicite).

    //Tem que fazer tratamento de erro;
    if(retornaNoById(i)==NULL)
        cout << "No com ID " << i << " nao existe." << endl;
    else if(retornaNoById(j)==NULL)
        cout << "No com ID " << j << " nao existe." << endl;
    else
    {
        int res=0;
        cout << "Qual algoritmo deseja usar?" << endl;
        cout << "(1) Algoritmo de Dijkstra" << endl;
        cout << "(2) Algoritmo de Floyd" << endl;
        while(res<1 || res>2)
        {
            cin >> res;
            if(res<1 || res>2)
                cout << "Erro! Digite novamente: ";
        }
        if(res==1) //Moore-Dijkstra
        {
            ///Deu ruim copiar do slide kk Não entendi nada
        }
        else //Floyd
        {
            /*Algoritmo copiado e, em alguns detalhes, já adaptado dos Slides
            for(int i = 1; i<=n; i++)
            {
                for(int j = 1; j<=n; j++)
                    ///A0(i,j) ← cij
            }
            for(int k = 1; k<=n; k++)
            {
                for(int i = 1; i<=n; i++)
                {
                    for(int j = 1; j<=n; j++)
                    {
                        ///Ak(i,j) ← min{Ak-1(i,j),
                        ///Ak-1(i,k) + Ak-1(k,j)}
                    }
                }
            }*/
        }
    }
}

int Grafo::grauGrafo()
{
    int grau = primeiroNo->getGrau();
    No *n;
    for(n=primeiroNo; n->getProx()!=NULL; n=n->getProx())
    {
        if(grau < n->getGrau())
            grau=n->getGrau();
    }
    return grau;
}

int Grafo::grauInGrafo()
{
    int grau = primeiroNo->getGrauIn();
    No *n;
    for(n=primeiroNo; n->getProx()!=NULL; n=n->getProx())
    {
        if(grau < n->getGrauIn())
            grau=n->getGrauIn();
    }
    return grau;
}

int Grafo::grauOutGrafo()
{
    int grau = primeiroNo->getGrauOut();
    No *n;
    for(n=primeiroNo; n->getProx()!=NULL; n=n->getProx())
    {
        if(grau < n->getGrauOut())
            grau=n->getGrau();
    }
    return grau;
}

void Grafo::fechoTransDireto(int id) ///FAZER FUNÇÃO (somente digrafo)
{
    /*O fecho transitivo direto (ftd) de um vértice v é o conjunto de todos os vértices que
    podem ser atingidos por algum caminho iniciando em v. O ftd do vértice x5 do grafo G17,
     por exemplo, é o conjunto: {x1, x2, x3, x4, x5, x6}. Note que o próprio vértice faz parte
      do ftd já que ele é alcançável partindo-se dele mesmo.  */
}

void Grafo::fechoTransIndireto(int id) ///FAZER FUNÇÃO (somente digrafo)
{
    /**
    *p) Retornar o fecho transitivo indireto de um dado nó
    *informado pelo usuário;
    **/
}

void Grafo::sequenciaGraus() //Apresentar a sequência de graus;
{
    cout << "Sequencia de graus: (";
    No *n;
    for(n=primeiroNo; n!=NULL; n=n->getProx())
    {
        if(n->getProx()==NULL) //Quando chegar no último nó fechar parenteses.
            cout << n->getGrau() << ")"<<endl;
        else
            cout << n->getGrau() << ", ";
    }
}

void Grafo::sequenciaGrausIn() //Apresentar a sequência de graus de entrada;
{
    cout << "Sequência de graus de entrada: (";
    No *n;
    for(n=primeiroNo; n->getProx()!=NULL; n=n->getProx())
    {
        if(n->getProx()==NULL) //Quando chegar no último nó fechar parenteses.
            cout << n->getGrauIn() << ").";
        else
            cout << n->getGrauIn() << ", ";
    }
}

void Grafo::sequenciaGrausOut() //Apresentar a sequência de graus de saida;
{
    cout << "Sequência de graus de saída: (";
    No *n;
    for(n=primeiroNo; n->getProx()!=NULL; n=n->getProx())
    {
        if(n->getProx()==NULL) //Quando chegar no último nó fechar parenteses.
            cout << n->getGrauOut() << ").";
        else
            cout << n->getGrauOut() << ", ";
    }
}

Grafo* Grafo::subgrafoInduzido(int vet[], int tam)
{
    Grafo* subGrafo = new Grafo();
    int i, j;
    Aresta* aux;
    for(i = 0; i<tam; i++)
    {
        subGrafo->incluiNo(vet[i]);
    }
    for(i = 0; i<tam; i++)
    {
        for(j = 0; j<tam; j++)
        {
            if(verificaMultigrafo())
                aux =procuraArestaMultigrafo(retornaNoById(vet[i]),retornaNoById(vet[j]));
            else
                aux = procuraAresta(retornaNoById(vet[i]),retornaNoById(vet[j]));

            if(aux!=NULL)
                subGrafo->incluiAresta(vet[i],vet[j],aux->getPeso());
        }
    }
    return subGrafo;
}

Grafo* Grafo::complementar()
{
    Grafo* grafoCompl = new Grafo();
    No *i, *j;
    for(i=primeiroNo; i!=NULL; i=i->getProx())
    {
        grafoCompl->incluiNo(i->getId());
    }
    for(i=primeiroNo; i!=NULL; i=i->getProx())
    {
        for(j=i; j!=NULL; j=j->getProx())
        {

            if(i!=j)
            {
                if(procuraAresta(i,j)==NULL)
                    grafoCompl->incluiAresta(i->getId(),j->getId(),0);
            }
        }
    }
    return grafoCompl;
}

Grafo* Grafo::componenteFortementeConexa() ///FAZER FUNÇÃO
{
    /**
     *t) Para digrafos, apresentar as componentes fortemente
     *conexas;
    **/
    Grafo* grafo = new Grafo();
    return grafo;
}

bool Grafo::verificaConexo()
{
    for(No* n=primeiroNo; n->getProx()!=NULL; n=n->getProx())
    {
        if(n->getComponente()!=1)
            return false;
    }
    return true;
}

bool Grafo::euleriano() ///conferir componente fortemente conexa;
{
    No *n;
    if(digrafo)
    {
        for(n=primeiroNo; n->getProx()!=NULL; n=n->getProx())
        {
            if(n->getGrauIn()!=n->getGrauOut())
                return false;
        }
    }
    else
    {
        if(verificaConexo())
        {
            for(n=primeiroNo; n->getProx()!=NULL; n=n->getProx())
            {
                if(n->getGrau()%2==1)
                    return false;
            }
        }
        else
            return false;
    }
    return true;
}

No* Grafo::noArticulacao() ///FAZER FUNÇÃO
{
    int vet[ordem];
    No* n;
    int i=0, comp, id;
    for(n= primeiroNo; n!=NULL; n=n->getProx())
    {
        vet[i]=n->getId();
        i++;
    }
    Grafo* grafo=subgrafoInduzido(vet,ordem);
    grafo->buscaProfudidade();
    comp = componentes;
    for(n=grafo->primeiroNo; n!=NULL; n=n->getProx())
    {
        vector<int> vetor;
        i=0;
        for(Adjacente* adj=n->lista->getPrimeiro(); adj!=NULL; adj=adj->getProx())
        {
            vetor.push_back(adj->getId());
            i++;
        }
        id=n->getId();
        excluiNo(id);
        grafo->buscaProfudidade();
        if(componentes!=comp)
            return retornaNoById(id);
        else
        {
            grafo->incluiNo(id);
            for(i=0; i<vetor.size();i++)
                grafo->incluiAresta(id,vetor.at(i),0);
        }
    }
    cout << "Nao tem no de articulacao!" << endl;
    exit(0);
}

Aresta* Grafo::arestaPonte() ///FAZER FUNÇÃO
{
    /*
    *w) Apresentar as arestas ponte;
    */
}

void Grafo::raio() ///FAZER FUNÇÃO
{
    //Raio: excentricidade mínima de um vér tice do grafo.
}

void Grafo::diametro() ///FAZER FUNÇÃO
{
    //Diâmetro: excentricidade máxima de um  vértice do grafo.
}

void Grafo::centro() ///FAZER FUNÇÃO
{
    //Centro: conjunto de todos pontos centrais de G.
}

void Grafo::periferia() ///FAZER FUNÇÃO
{

}

Grafo* Grafo::agm() ///FAZER FUNÇÃO
{
    /*
    *y) Apresentar a AGM do grafo ou as florestas de custo
    *mínimo;*/
    //Criar uma lista L com as arestas ordenadas em ordem crescente de pesos.
    //Grafo* g = new Grafo();
    //Algoritmo copiado de ordenação
    Aresta* vetor[m];

    ordenaAresta(*vetor);

    for(int i=0; i<m; i++)
    {
        cout << vetor[i]->getPeso() << " ";
        vetor[i]->imprime();
    }

    /*Criar |V| subárvores contendo cada uma um nó isolado.
    F ← ∅
    int cont = 0;
    while(cont < m-1 && L!=0)
    {
        Seja (u,v) o próximo arco de L.
        L ← L – {(u,v)}
        if(u e v não estão na mesma subárvore)
        {
            F ← F ∪ {(u,v)}
            Unir as subárvores que contêm u e v.
            contador ← contador + 1
        }
    }
    return g;*/
}

Grafo* Grafo::arvoreBusca() ///FAZER FUNÇÃO
{
    /*
    *z) Apresentar as árvores de busca em profundidade e em
    *largura.
    **/
}

bool Grafo::getDigrafo()
{
    return digrafo;
}

bool Grafo::getPonderado()
{
    return ponderado;
}

void Grafo::imprimeListaArestas()
{
    for(Aresta* a = primeiraAresta; a!=NULL; a=a->getProx())
        cout << a->getNoAnt()->getId() << " para " <<  a->getNoProx()->getId() << ", peso " << a->getPeso() << endl;
    if(primeiraAresta==NULL)
        cout << "Primeira aresta NULL" << endl;
}

void Grafo::ordenaAresta(Aresta vetor[])
{
    Aresta *aux;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(vetor[i].getPeso()>vetor[j].getPeso())
            {
                aux=&vetor[i];
                vetor[i]=vetor[j];
                vetor[j]=*aux;
            }
        }
    }
}

