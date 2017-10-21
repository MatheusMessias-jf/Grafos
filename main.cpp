#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>
#include <cctype>
#include <iostream>
#include <locale.h>
#include <vector>
//#include "No.h"
//#include "Aresta.h"
//#include "Grafo.h"
#include "Funcao.h"

using namespace std;

//fksljlksdfjsfslkjsf
class Grafo;

int main(int argc, char* argv[])
{
    /*vector<string> argList;
    for(int i=0;i<argc;i++)
        argList.push_back(argv[i]);

    cout<<argv[1];
    system("pause");
    */

    Funcao nova;
    Grafo* grafo = nova.leituraTxt(/*argv*/);
    int num;
    do{
    num = nova.exibeMenu(false);
    nova.chamaFuncaoEscolhida(grafo,num);
    }while(num);
}

