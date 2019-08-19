#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int v; //Numero de vertices do Graph
    list<int>*adj; //ponteiro para um array contendo as listas de adjacencias.
public:
    Graph(int V);
    void addAresta(int v1, int v2); //adiciona aresta no Graph

    int outputDegree(int v);

    bool checkNeighbor(int v1,int v2); //verifica se v1 � vizinho de v2.

};

Graph::Graph(int v)
{
    this->v = v; //numero de vertices atribuido
    adj = new list<int>[v]; //Cria as listas de adjacencias.
}

void Graph::addAresta(int v1, int v2)
{
    adj[v1].push_back(v2); //adiciona vertice v2 na lista de adjacencia de v1
}

int Graph::outputDegree(int v)
{
    return adj[v].size(); //cada vertice possui uma lista de adjacencia, a quantidade de listas define a quantidade de vizinhos que esse vertice sai
}

bool Graph::checkNeighbor(int v1,int v2)
{
    if(find(adj[v1].begin(),adj[v1].end(),v2) != adj[v1].end()) //find busca do primeiro parametro ate o segundo, o elemento do terceiro parametro
        return true;
    return false;
}

int main(int argc, char * argv[])
{
    Graph Graph(4);

    Graph.addAresta(0,1);
    Graph.addAresta(0,3);
    Graph.addAresta(1,2);
    Graph.addAresta(3,1);
    Graph.addAresta(3,2);

    cout << "Grau de saida do vertice 3: " << Graph.outputDegree(3);
	return 0;
}
