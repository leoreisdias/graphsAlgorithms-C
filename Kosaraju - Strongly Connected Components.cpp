#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
	int vertice;
	list<int> * adj;
	
	void fill(int v,bool checked[], stack<int>&pilha)
	{
		// Marca o v�rtice atual como checked;
		checked[v] = true;
		
		// Percorre os adjacentes do vertice corrente
		list<int>::iterator it;
		for(it = adj[v].begin(); it != adj[v].end();it++){
			if(!checked[*it])
				fill(*it,checked,pilha);
		}
		pilha.push(v);
	}
	
	void DFS(int v,bool checked[])
	{
		//Marca o vertice corrente como checked
		checked[v] = true;
		
		//Imprime o vertice corrente
		cout << v << " ";
		
		list<int>::iterator it;
		for(it=adj[v].begin();it!=adj[v].end();it++)
			if(!checked[*it]){
				DFS(*it,checked);
			}		
    }	
	
	Graph(int v){
		vertice = v;
		adj = new list<int>[v];
	}	
	
	void add_aresta(int v1,int v2){
		adj[v1].push_back(v2);
	}
	
	// Gera o Graph Transposto (Inverte o direcionamento)
	Graph Graph_transposto()
	{
		Graph novo_Graph(vertice);
		
		for(int i=0;i<vertice;i++){
			list<int>::iterator it;
			for(it=adj[i].begin();it != adj[i].end();it++){
				novo_Graph.adj[*it].push_back(i);
			}
		}
		
		return novo_Graph;
	}
	
	void Kusaraju(){
		stack<int> pilha;
		bool * marked = new bool[vertice];
		
		for(int i=0;i<vertice;i++)
			marked[i] = false;
		
		//fillr a pilha
		for(int i=0;i<vertice;i++){
			if(!marked[i])
				fill(i,marked,pilha);
		}
		// Ter o Graph transposto
		Graph Graph_t = Graph_transposto();
		
		// Marca todos como n�o marked novamente
		for(int i=0;i<vertice;i++)
			marked[i] = false;
		
		while(!pilha.empty()){ // Pilha com elementos por busca do Graph original
			
			//Imprime seguindo a ordem dos elementos da Pilha (Ordem da DFS no Graph normal)
			int v = pilha.top();
			
			pilha.pop();
			
			//Imprime cada elemento fortemente conexa
			if(!marked[v]){
				Graph_t.DFS(v,marked);
				cout << endl;
			}
		}
		
	}
};

int main(int argc, char *argv[])
{
	Graph Graph(4);
	Graph.add_aresta(0,1);
	Graph.add_aresta(1,3);
	Graph.add_aresta(2,3);
	Graph.add_aresta(3,0);

	
	//g.DFS(2,checked);
	Graph.Kusaraju();

	
	return 0;
}