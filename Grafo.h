#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED
//#include "No.h"
//#include "Aresta.h"

class Grafo{
private:
    int ordem;
    int m;
    No* primeiroNo;
    Aresta* primeiraAresta;
    Aresta* ultimaAresta;
    bool digrafo;
    bool ponderado; ///Um ponderado pra n� e outro para aresta?
    bool bipartido;
    int componentes;

public:
    Grafo();
    No* ultimoNo;
    ~Grafo();
    void incluiNo(int id);
    bool vazio(); //Verifica se o grafo � vazio
    void incluiAresta(int noI, int noJ, float peso);
    void excluiNo(int id);
    No* retornaNoById(int id); //Busca n� dado o ID
    Aresta* procuraAresta(No* i, No* j);
    Aresta* procuraArestaMultigrafo(No* i, No* j);
    void excluiAresta(int i, int j);
    int retornaGrauNo(int id); //Grau
    int retornaGrauInNo(int id); //Grau de entrada
    int retornaGrauOutNo(int id); //Grau de sa�da
    bool verificaKRegularidade(int k); //Verificar a k-regularidade do grafo (k informado pelo usu�rio);;
    int infoOrdem(); // Informa a ordem do grafo (n�mero de n�s);;
    bool infoTrivial(); // Informar se o grafo � trivial;
    bool infoNull(); //Informar se o grafo � nulo;
    void vizinhancaAberta(int id); //Mostrar a vizinhan�a aberta de um dado n� informado pelo usu�rio;
    void vizinhancaFechada(int id); //Mostrar a vizinhan�a fechada de um dado n� informado pelo usu�rio;
    bool verificaMultigrafo();//Verificar se o grafo � um multigrafo;
    bool verificaCompleto(); //� completo se tiver um par de aresta para todo n� i, j;
    bool verificaBipartido();//Verificar se o grafo � bipartido;
    float caminhoMin(int i, int j);
    int grauGrafo();
    int grauInGrafo();
    int grauOutGrafo();
    void fechoTransDireto(int id);
    void fechoTransIndireto(int id);
    void sequenciaGraus(); //Apresentar a sequ�ncia de graus;
    void sequenciaGrausIn(); //Apresentar a sequ�ncia de graus de entrada;
    void sequenciaGrausOut(); //Apresentar a sequ�ncia de graus de saida;
    Grafo* subgrafoInduzido(int vet[], int tam);
    Grafo* complementar();
    Grafo* componenteFortementeConexa();
    bool verificaConexo();
    bool euleriano();
    No* noArticulacao();
    Aresta* arestaPonte();
    void raio();
    void diametro();
    void centro();
    void periferia();
    Grafo* agm();
    Grafo* arvoreBusca();
    bool getDigrafo();
    bool getPonderado();
    void imprimeNoAdjacentes();
    void buscaProfudidade();
    void prof(No* n, char* auxB, int comp);
    void imprimeListaArestas();
    void ordenaAresta(Aresta* vetor);
};

#endif // GRAFO_H_INCLUDE

