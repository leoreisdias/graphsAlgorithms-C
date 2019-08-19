// DFS - Busca em Profundidade
// Verifica, entra na pilha, volta e sai da pilha, termina quando todos estiverem visitados e a pilha vazia.
#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int v; //Numero de vertices do grafo
    list<int>*adj; //ponteiro para um array contendo as listas de adjacencias.
public:
    Graph(int V);
    void addAresta(int v1, int v2); //adiciona aresta no grafo
    void DFS(int v);
};

Graph::Graph(int v)
{
    this->v = v; //numero de vertices atribuido
    adj = new list<int>[v]; //Cria as listas de adjacencias.
}

void Graph::addAresta(int v1, int v2)
{
    adj[v1].push_back(v2); //adiciona vertice v2 na lista de adjacencia de v1
    adj[v2].push_back(v1);
}

void Graph::DFS(int v)
{
    stack<int>pilha;
    bool visitados[v]; //vetor dos vertices que foram visitados
    for(int i=0;i<v;i++)
        visitados[i] = false;

    while(true)
    {
        if(!visitados[v])
        {
            cout << "Visitando o vertice " << v << " ...\n";
            visitados[v] = true;
            pilha.push(v);
        }

        bool achou = false;
        list<int>::iterator it;

        // Busca por um vizinho N�O visitado
        for(it=adj[v].begin();it!=adj[v].end();it++)
        {
            if(!visitados[*it])
            {
                achou=true;
                break;
            }
        }

        if(achou)
            v = *it; // Atualiza o V
        else
        {
            // Se n�o h� mais visinhos n�o visitados, retira da pilha ao dar backtracking
            pilha.pop();

            // Busca termina quando a pilha esvazia
            if(pilha.empty()) break;

            // Se n�o esvaziou o v recebe o novo topo apos o .pop() como backtracking para verificar se h� outros visinhos n�o visitados desse topo
            v = pilha.top();
        }
    }
}

int main(int argc, char * argv[])
{
    Graph grafo(8);

    grafo.addAresta(0,1);
    grafo.addAresta(0,2);
    grafo.addAresta(1,3);
    grafo.addAresta(1,4);
    grafo.addAresta(2,5);
    grafo.addAresta(2,6);
    grafo.addAresta(6,7);

    grafo.DFS(0);

	return 0;
}
