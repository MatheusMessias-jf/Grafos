#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>
#include <cctype>
#include <iostream>
#include <locale.h>
//#include "No.h"
//#include "Aresta.h"
//#include "Grafo.h"
//#include "Funcao.h"

using namespace std;

Funcao::Funcao() {

}

Funcao::~Funcao() {

}

int Funcao::exibeMenu(Grafo* grafo)
{
    setlocale(LC_ALL, "Portuguese");
    int opMenu;
    cout << "------------------ MENU ------------------" << endl;
    cout << "1- Inclusão e exclusão de nó e de aresta;" << endl;
    cout << "2- Informações sobre o grafo" << endl;
    cout << "3- Retornar o grau de um dado nó" << endl;
    cout << "4- Mostrar a vizinhança aberta de um dado nó" << endl;
    cout << "5- Mostrar a vizinhança fechada de um dado nó" << endl;
    cout << "6- Retornar o fecho transitivo direto de um dado nó" << endl;
    cout << "7- Retornar o fecho transitivo indireto de um dado nó" << endl;
    cout << "8- Apresentar a sequência de graus" << endl;
    cout << "9- Apresentar o subgrafo induzido por um dado conjunto de vértices" << endl;
    cout << "10- Apresentar o complementar do grafo" << endl;
    cout << "11- Apresentar os nós de articulação " << endl;
    cout << "12- Apresentar as arestas ponte" << endl;
    cout << "13- Apresentar o raio, o diâmetro, o centro e a periferia do grafo" << endl;
    cout << "14- Apresentar a AGM do grafo ou as florestas de custo mínimo" << endl;
    cout << "15- Apresentar as árvores de busca em profundidade e em largura " << endl;
    cout << "16- Apresentar as componentes fortemente conexas" << endl;
    cout << "0 ou outro- Sair" << endl;
    cout << "Opção: ";
    cin >> opMenu;
    system("cls");
    return opMenu;
}

void Funcao::chamaFuncaoEscolhida(Grafo* grafo, int opMenu)
{
    int id;
    switch (opMenu)
    {
    case 1:
        exibeSubMenu(grafo);
        break;
    case 2:
        exibeSubMenu2(grafo);
        break;
    case 3:
        cout << "Digite o ID do nó:";
        cin >> id;
        if(grafo->getDigrafo())
        {
            cout << "Grau de entrada do nó " << id <<": " << grafo->retornaGrauInNo(id) << endl;
            cout << "Grau de saída do nó " << id <<": " << grafo->retornaGrauOutNo(id) << endl;
        }
        else
            cout << "Grau do nó " << id << ": " << grafo->retornaGrauNo(id)<< endl;
        break;
    case 4:
        cout << "Digite o ID do nó:";
        cin >> id;
        grafo->vizinhancaAberta(id);
        break;
    case 5:
        cout << "Digite o ID do nó:";
        cin >> id;
        grafo->vizinhancaFechada(id);
        break;
    case 6:
        cout << "Digite o ID do no:";
        cin >> id;
        grafo->fechoTransDireto(id);
        break;
    case 7:
        cout << "Digite o ID do no:";
        cin >> id;
        grafo->fechoTransIndireto(id);
        break;
    case 8:
        if(grafo->getDigrafo())
        {
            grafo->sequenciaGrausIn();
            grafo->sequenciaGrausOut();
        }
        else
            grafo->sequenciaGraus();
    break;
    case 9:
    {
        int num;
        cout << "Digite a quantidade de nós do subgrafo induzido: ";
        cin >> num;
        int vet[num];
        for(int i=0; i<num; i++)
        {
            cout <<"Digite o ID do " << i+1 << "o nó: ";
            cin >> id;
            vet[i] = id;
        }
        Grafo* subGrafo = grafo->subgrafoInduzido(vet, num);
        subGrafo->imprimeListaArestas();
        subGrafo->imprimeNoAdjacentes();
    }
    break;
    case 10:
    {
        Grafo* g = grafo->complementar();
        g->imprimeListaArestas();
        g->imprimeNoAdjacentes();
    }
        break;
    case 11:
        grafo->noArticulacao();
        break;
    case 12:
        grafo->arestaPonte();
        break;
    case 13:
        grafo->raio();
        grafo->diametro();
        grafo->centro();
        break;
    case 14:
        grafo->agm();
        break;
    case 15:
        grafo->arvoreBusca();
        break;
    case 16:
        if(grafo->getDigrafo())
            grafo->componenteFortementeConexa();
        else
            cout<<"Não e digrafo";
        break;
    case 17:
        grafo->imprimeListaArestas();
        grafo->imprimeNoAdjacentes();
        break;
    default:
        cout << "Algoritmo Encerrado. Os dados foram armazenados em arquivo." << endl;
    }
}

void Funcao::exibeSubMenu(Grafo* grafo)
{
    int id;

    setlocale(LC_ALL, "Portuguese");
    int opMenu;
    cout << "------------------ SubMenu ------------------" << endl;
    cout << "1- Incluir nó" << endl;
    cout << "2- Excluir nó" << endl;
    cout << "3- Incluir aresta" << endl;
    cout << "4- Excluir aresta" << endl;
    cout << "0 ou outro- voltar" << endl;
    cout << "Opção: ";
    cin >> opMenu;
    system("cls");

    switch (opMenu)
    {
    case 1:
        cout << "Digite o ID do nó:";
        cin >> id;
        grafo->incluiNo(id);
        break;
    case 2:
        cout << "Digite o ID do nó:";
        cin >> id;
        grafo->excluiNo(id);
        break;
    case 3:
        int n1, n2, peso;
        cout << "ID do nó i:";
        cin >> n1;
        cout << "ID do nó j:";
        cin >> n2;
        if(grafo->getPonderado())
        {
            cout << "Peso da aresta:";
            cin >> peso;
        }
        else
            peso = 0;
        grafo->incluiAresta(n1,n2,peso);
        break;
    case 4:
        int noI, noJ;
        cout << "ID do nó i:";
        cin >> noI;
        cout << "ID do nó j:";
        cin >> noJ;
        grafo->excluiAresta(noI, noJ);
        break;
    default: break;
    }
}

void Funcao::exibeSubMenu2(Grafo* grafo)
{
    setlocale(LC_ALL, "Portuguese");
    int opMenu;
    cout << "------------------ SubMenu ------------------" << endl;
    cout << "1- Retornar o grau do grafo" << endl;
    cout << "2- Verificar a k-regularidade do grafo " << endl;
    cout << "3- Informar a ordem do grafo " << endl;
    cout << "4- Informar se o grafo é trivial" << endl;
    cout << "5- Informar se o grafo é nulo" << endl;
    cout << "6- Verificar se o grafo é um multigrafo" << endl;
    cout << "7- Verificar se o grafo é completo" << endl;
    cout << "8- verificar se o grafo é bipartido" << endl;
    cout << "9- Verificar se o grafo é eulerianos" << endl;
    cout << "0 ou outro- voltar" << endl;
    cout << "Opção: ";
    cin >> opMenu;
    system("cls");

    switch (opMenu)
    {
    case 1:
        if(grafo->getDigrafo())
        {
            cout << "Grau de entrada do grafo: " << grafo->grauInGrafo() << endl;
            cout << "Grau de saída do grafo: " << grafo->grauOutGrafo() << endl;
        }
        else
            cout << "Grau do grafo: " << grafo->grauGrafo() << endl;
        break;
    case 2:
        int k;
        cout << "Digite o valor de k: ";
        cin >> k;
        if(grafo->verificaKRegularidade(k))
            cout << "O grafo é " << k << "-regular." <<endl;
        else
            cout << "O grafo não é " << k << "-regular." <<endl;
        break;
    case 3:
        cout << "Ordem do grafo: " << grafo->infoOrdem() << endl;
        break;
    case 4:
        if(grafo->infoTrivial())
            cout << "O grafo é trivial." << endl;
        else
            cout << "O grafo não é trivial." << endl;
        break;
    case 5:
        if(grafo->infoNull())
            cout << "O grafo é nulo." << endl;
        else
            cout << "O grafo não é nulo." << endl;
        break;
    case 6:
        if(grafo->verificaMultigrafo())
            cout << "O grafo é multigrafo." << endl;
        else
            cout << "O grafo não é multigrafo." << endl;
        break;
    case 7:
        if(grafo->verificaCompleto())
            cout << "O grafo é completo." << endl;
        else
            cout << "O grafo não é completo." << endl;
        break;
    case 8:
        if(grafo->verificaBipartido())
            cout << "O grafo é bipartido." << endl;
        else
            cout << "O grafo não é bipartido." << endl;
        break;
    case 9:
        if(grafo->euleriano())
            cout << "O grafo é euleriano." << endl;
        else
            cout << "O grafo não é euleriano." << endl;
        break;
    default: break;
    }
}

Grafo* Funcao::leituraTxt(/*char* arquivo[]*/)
{
    ifstream file("Instancia.txt"/*arquivo[0]*/);
    if (!file)
        cout << "Erro ao abrir o arquivo";

    int size;
    if (!(file >> size))
        cout << "Falhou em ler o primeiro valor!";

    Grafo* grafo= new Grafo();

    for (int i = 1; i <= size; i++)
    {
        grafo->incluiNo(i);
        //cout << grafo->ultimoNo->getId();
    }

    while (!file.eof())
    {
        int a, b, c;
        file >> a >> b >> c;
        grafo->incluiAresta(a,b,c);
    }
    file.close();
    return grafo;
}

void Funcao::escritaTxt(int i, int j, int peso) // escreve no arquivo novos valores de j, k e peso
{
    ofstream myfile("escrita.txt");

    if (myfile.is_open())
    {
        //myfile << infoOrdem(); primeira linha do novo arquivo será a nova ordem caso alterada
        myfile << i << " " << j << " " << peso << "\n";
        myfile.close();
    }
    else
        cout << "Impossivel abrir o arquivo!";
}

float Funcao::excentricidade(){

}


