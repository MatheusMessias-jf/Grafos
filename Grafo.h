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
    bool ponderado; ///Um ponderado pra nó e outro para aresta?
    bool bipartido;
    int componentes;

public:
    Grafo();
    No* ultimoNo;
    ~Grafo();
    void incluiNo(int id);
    bool vazio(); //Verifica se o grafo é vazio
    void incluiAresta(int noI, int noJ, float peso);
    void excluiNo(int id);
    No* retornaNoById(int id); //Busca nó dado o ID
    Aresta* procuraAresta(No* i, No* j);
    Aresta* procuraArestaMultigrafo(No* i, No* j);
    void excluiAresta(int i, int j);
    int retornaGrauNo(int id); //Grau
    int retornaGrauInNo(int id); //Grau de entrada
    int retornaGrauOutNo(int id); //Grau de saída
    bool verificaKRegularidade(int k); //Verificar a k-regularidade do grafo (k informado pelo usuário);;
    int infoOrdem(); // Informa a ordem do grafo (número de nós);;
    bool infoTrivial(); // Informar se o grafo é trivial;
    bool infoNull(); //Informar se o grafo é nulo;
    void vizinhancaAberta(int id); //Mostrar a vizinhança aberta de um dado nó informado pelo usuário;
    void vizinhancaFechada(int id); //Mostrar a vizinhança fechada de um dado nó informado pelo usuário;
    bool verificaMultigrafo();//Verificar se o grafo é um multigrafo;
    bool verificaCompleto(); //É completo se tiver um par de aresta para todo nó i, j;
    bool verificaBipartido();//Verificar se o grafo é bipartido;
    float caminhoMin(int i, int j);
    int grauGrafo();
    int grauInGrafo();
    int grauOutGrafo();
    void fechoTransDireto(int id);
    void fechoTransIndireto(int id);
    void sequenciaGraus(); //Apresentar a sequência de graus;
    void sequenciaGrausIn(); //Apresentar a sequência de graus de entrada;
    void sequenciaGrausOut(); //Apresentar a sequência de graus de saida;
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

