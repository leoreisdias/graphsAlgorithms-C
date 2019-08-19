// Algoritmo de Kruskal
// Para detectar ciclo usando Union Find

#include<bits/stdc++.h>
using namespace std;

class Edge
{
    int vertice1, vertice2, weight;

public:
    Edge(int v1, int v2, int weight){
        vertice1 = v1;
        vertice2 = v2;
        this->weight = weight;
    }

    int getVertice1(){
        return vertice1;
    }
    int getVertice2(){
        return vertice2;
    }
    int getweight(){
        return weight;
    }

    // Sobrescrever operador <
    bool operator<(const Edge& Edge2){
        return (weight < Edge2.weight);
    }
};

class Grafo
{
    int v; // vertices
    vector<Edge> Edges;

public:

    Grafo(int v){
        this->v = v;
    }

    void add_Edge(int v1, int v2, int weight){
        Edge Edge(v1,v2,weight);
        Edges.push_back(Edge);
    }

    // Fun��o Find do Union Find
    int finding(int subset[],int d){
        if(subset[d] == -1)
            return d;
        return finding(subset,subset[d]);
    }

    // Fun��o Union do Union Find
    void Union(int v1,int v2,int subset[]){
        int v1_set = finding(subset,v1);
        int v2_set = finding(subset,v2);

        subset[v1_set] = v2_set;
    }

    // FUN��O DE KRUSKAL
    void kruskal()
    {
        vector<Edge> tree;
        int tam_Edges = Edges.size();

        sort(Edges.begin(),Edges.end());

        int *subset = new int[v];

        memset(subset,-1,sizeof(int)*v);

        for(int i=0; i<tam_Edges; i++){
            int v1 = finding(subset,Edges[i].getVertice1());
            int v2 = finding(subset,Edges[i].getVertice2());

            if(v1 != v2) // Se for diferente nenhum dos vertices da Edge atual gera ciclo.
            {
                tree.push_back(Edges[i]);
                Union(v1,v2,subset);
            }
        }

        int size_tree = tree.size();

        for(int i=0;i<size_tree;i++){
            char v1 = 'A' + tree[i].getVertice1(); // Exibir com Letras ao inves de Numero, soma � tabela ASCII
            char v2 = 'A' + tree[i].getVertice2();
            cout << "(" << v1 << ", " << v2 << ") = " << tree[i].getweight() << endl;
        }
    }
};

int main(int argc, char * argv[])
{
    Grafo grafo(7);

    grafo.add_Edge(0,1,7);
    grafo.add_Edge(0,3,5);
    grafo.add_Edge(1,2,8);
    grafo.add_Edge(1,3,9);
    grafo.add_Edge(1,4,7);
    grafo.add_Edge(2,4,5);
    grafo.add_Edge(3,4,15);
    grafo.add_Edge(3,5,6);
    grafo.add_Edge(4,5,8);
    grafo.add_Edge(4,6,9);
    grafo.add_Edge(5,6,11);

    grafo.kruskal();

    return 0;
}
