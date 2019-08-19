// Union-find -> Detecta Ciclo em Grafo Não Direcionado

#include<bits/stdc++.h>
using namespace std;

int busca(int subset[], int v)
{
    if(subset[v] == -1)
        return v;
    return busca(subset,subset[v]);
}

int uniao(int subset[], int v1, int v2)
{
    int novo_v1 = busca(subset,v1);
    int novo_v2 = busca(subset,v2);

    subset[novo_v1] = novo_v2;
}

int ciclo(int grafo[3][3])
{
    int * subset = (int*)malloc(3*sizeof(int));
    memset(subset,-1,sizeof(int)*3);

    for(int i = 0;i<3;i++)
    {
        for(int j = i;j<3;j++)
        {
            if(grafo[i][j] == 1)
            {
               int v1 = busca(subset,i);
               int v2 = busca(subset,j);

                if(v1 == v2)
                    return 1;
                else
                    uniao(subset,v1,v2);
            }
        }
    }

    return 0;
}

int main(int argc, char * argv[])
{
    int grafo[3][3] =
    {
        {0,1,1},
        {1,0,1},
        {1,1,0}
    };

    if(ciclo(grafo)) cout << "Possui Ciclo\n";
    else
        cout << "Nao tem ciclo\n";
	return 0;
}
