#include <bits/stdc++.h>
using namespace std;

vector<int>g[11234567];
int visited[11234567];

void dfs(int vertex){
	// Here you process
	// the vertex and mark it
	// as a visited vertex
	printf ("%d ", vertex);
	visited[vertex] = 1;


	for (int i = 0; i < g[vertex].size(); i++){
		int nextVertex = g[vertex][i];
		// If next vertex has not yet been visited
		if (visited[nextVertex] == 0)
			dfs(nextVertex);
	}
}

int main(){
	printf ("\nDigite a quantidade de vértices e a quantidade de arestas: ");
	int V,A; scanf ("%d %d", &V, &A);
	printf ("\n\nOs vértices serão enumerados de 0 até %d. Digite agora as %d arestas.\nCada uma das %d linhas tem que conter 2 números entre 1 e %d\nrepresentando uma aresta saindo do primeiro e chegando no segundo vértice.\n", V-1, A, A, V);

	for (int i = 0; i < A; i++){
		int u,v; scanf ("%d %d", &u, &v);
		g[u].push_back(v);
	}
	printf ("\n\nVértices processados na ordem: ");
	for (int vertex = 0; vertex < V; vertex++){
		if (visited[vertex] == 0)
			dfs(vertex);
	}
	printf ("\n\n");
}