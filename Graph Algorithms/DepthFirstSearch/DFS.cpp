#include <iostream>
#include <list>
#include <cstdlib>
using namespace std;

class Graph {
	private:
		list<int> *adj;
		int vertice;
	public:
		Graph(int vertice);
		void addEdge(int source, int destination);
		void DFS(int vertex);
};

Graph::Graph(int vertice) {
	this -> vertice = vertice;
	adj = new list<int>[vertice];
}

void Graph::addEdge(int source, int destination) {
	adj[source].push_back(destination);
}

void Graph::DFS(int vertex) {
	bool *visited = new bool[vertice];
	for (int i = 0; i < vertice; i++)
		visited[i] = false;
	visited[vertex] = true;
	cout << vertex <<" ";
	list<int>::iterator i;
	for (i = adj[vertex].begin(); i != adj[vertex].end(); i++) {
		if (!visited[*i]) 
			DFS(*i);
	}
}

int main() {
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.DFS(0);
}
