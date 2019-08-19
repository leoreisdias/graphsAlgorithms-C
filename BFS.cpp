// BFS - Busca em Largura
// Ao visitar coloca na Fila, o novo vertice corrente ser� todo proximo elemento que sair� da qFila, e a cada vertice corrente seus filhos entram na qFila
// Termina ao esvaziar toda a Fila e n�o ter nenhum outro n� para entrar.
#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int v; //Numero de vertices do grafo
    list<int>*adj; //ponteiro para um array contendo as listas de adjacencias.
public:
    Graph(int V);
    void addAresta(int v1, int v2); //adiciona aresta no grafo
    void BFS(int v);
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

void Graph::BFS(int v)
{
    // qFila para verifica��o de vertice corrente
    queue<int>qFila;
    bool checked[this->v];
    for(int i=0;i<this->v;i++)
        checked[i] = false;


    qFila.push(v); // Coloca o elemento raiz na qFila
    checked[this->v] = true;

    while(true)
    {
        cout << "Visitando o vertice " << v << " ...\n";
        qFila.pop(); // Tira da qFila ao fazer as opera��es com ele

        list<int>::iterator it;

        // Busca por um vizinho
        for(it=adj[v].begin();it!=adj[v].end();it++)
           if(!checked[*it])
            {
                qFila.push(*it); // Cada vizinho encontrado ainda N�O visitado, � colocado na qFila

                checked[*it] = true;
            }

            if(qFila.empty()) break; // Se a qFila est� vazia a busca foi concluida
            v = qFila.front(); // Caso n�o esteja vazia o novo n� corrente � o pr�ximo elemento a sair da qFila
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

    grafo.BFS(0);

	return 0;
}
