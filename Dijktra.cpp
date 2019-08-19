// Dijkstra - Graph

#include<bits/stdc++.h>
#define INFINITO 10000000
using namespace std;

class Graph
{
    int vertice;
    list< pair<int,int> > * adj;
public:

    Graph(int v){
        vertice = v;
        adj = new list< pair<int,int> >[vertice]; // Lista de Adjacencia com o vertice e peso
    }

    void add_aresta(int v1,int v2,int peso){
        adj[v1].push_back(make_pair(v2,peso));
    }

    int dijkstra(int orig, int dest)
    {
        int dist[vertice];
        int checked[vertice]; // Verificar se o vertice ja foi checked para n�o expandir mais.

        // Primeiro elemento do PAIR sendo a distancia e o segundo sendo o vertice
        priority_queue< pair<int,int>,vector< pair<int,int> >, greater<pair<int,int> > > pfila;

        for(int i=0;i<vertice;i++){
            dist[i] = INFINITO; // As primeiras distancias s�o infinitas por n�o ter expandido
            checked[i] = 0;
        }
        dist[orig] = 0; // Dist da origin pra ela mesma � Zero.
        pfila.push(make_pair(dist[orig],orig)); //Inseri na fila

        while(!pfila.empty()){
            pair<int,int> aux = pfila.top(); // Extrai o pair do topo
            int u = aux.second; // Obtem o vertice do pair
            pfila.pop(); // Remove o pair que estava na fila

            //Verificar se o vertice ja foi expandido
            if(!checked[u]){
                checked[u] = 1;

                list< pair<int,int> >::iterator it;
                for(it=adj[u].begin();it!=adj[u].end();it++){

                    //Obtem o vertice adjacente e custo da aresta
                    int v = it->first;
                    int edgeCost = it->second;

                    if(dist[v] > dist[u] + edgeCost){
                        dist[v] = dist[u] + edgeCost;
                        pfila.push(make_pair(dist[v],v));
                    }
                }
            }
        }
        return dist[dest];
    }
};

int main(int argc, char * argv[])
{
    Graph Graph(3);

    Graph.add_aresta(1,2,2);
    Graph.add_aresta(1,3,7);
    Graph.add_aresta(2,3,3);

    cout << "Caminho Minimo de 0 a 4: " << Graph.dijkstra(1,3) << endl;

	return 0;
}
