// Graphs - Verifica se um grafo direcionado tem ciclo

#include <bits/stdc++.h>

using namespace std;

class Graph
{
	int v; // n�mero de arestas
	list<int> *adj;

public:
	Graph(int v);
	void addAresta(int v1, int v2);

	// faz uma DFS a partir de um v�rtice, retorna se found ciclo ou n�o
	bool dfs(int vCorrente);

	// verifica se o Graph direcionado tem ciclo
	bool ciclo();
};

Graph::Graph(int v)
{
	this->v = v;
	adj = new list<int>[v];
}

void Graph::addAresta(int v1, int v2)
{
	adj[v1].push_back(v2);
}

bool Graph::dfs(int vCorrente)
{
	stack<int> pilha;
	bool checked[v], checked_stack[v];

	// inicializa checked e pilha_rec com false
	for(int i = 0; i < v; i++)
		checked[i] = checked_stack[i] = false;

	// faz uma DFS
	while(true)
	{
		bool found = false;
		list<int>::iterator it;

		if(!checked[vCorrente])
		{
			pilha.push(vCorrente);
			checked[vCorrente] = checked_stack[vCorrente] = true;
		}

		for(it = adj[vCorrente].begin(); it != adj[vCorrente].end(); it++)
		{
			// se o vizinho j� est� na pilha � porque existe ciclo
			if(checked_stack[*it])
				return true;
			else if(!checked[*it])
			{
				// se n�o est� na pilha e n�o foi visitado, indica que found
				found = true;
				break;
			}
		}

		if(!found)
		{
			checked_stack[pilha.top()] = false; // marca que saiu da pilha
			pilha.pop(); // remove da pilha
			if(pilha.empty())
				break;
			vCorrente = pilha.top();
		}
		else
			vCorrente = *it;
	}

	return false;
}

bool Graph::ciclo()
{
	for(int i = 0; i < v; i++)
	{
		if(dfs(i))
			return true;
	}
	return false;
}

int main(int argc, char *argv[])
{
	Graph Graph(4);

	Graph.addAresta(0,1);
	Graph.addAresta(0,2);
	Graph.addAresta(1,3);
	//Graph.addAresta(3,0);

	if(Graph.ciclo())
		cout << "Contem ciclo\n";
	else
		cout << "NAO contem ciclo\n";

	return 0;
}
