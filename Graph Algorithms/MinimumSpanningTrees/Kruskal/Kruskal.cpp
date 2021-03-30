#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define edge pair<int, int>

class Graph {
	private:
		vector<pair<int, edge>>GraphPair;
		vector<pair<int, edge>>TreePair;
		int vertices;
		int *parent;
	public:
		Graph(int vertices);
		void addEdge(int source, int destination, int weight);
		int FindSet(int vertex);
		void Union(int vertex, int dest);
		void Kruskal();
		void printGraph();
};
Graph::Graph(int vertices) {
	parent = new int[vertices];
	for (int i = 0; i < vertices; i++) 
		parent[i] = i;
	GraphPair.clear();
	TreePair.clear();
}
void Graph::addEdge(int source, int destination, int weight) {
	GraphPair.push_back(make_pair(weight, edge(source, destination)));
}

int Graph::FindSet(int vertex) {
	if (vertex == parent[vertex])
		return vertex;
	else 
		return FindSet(parent[vertex]);
}

void Graph::Union(int vertex, int dest) {
	parent[vertex] = parent[dest];
}
//Total running time: O(E lg E)
//O(E) for Union and find set
//O(E lg E) for the make set disjoint operation

void Graph::Kruskal() {
	int i, vertexRep, edgeRep;
	sort(GraphPair.begin(), GraphPair.end());
	for (int i = 0; i < GraphPair.size(); i++) {
		vertexRep = FindSet(GraphPair[i].second.first);
		edgeRep = FindSet(GraphPair[i].second.second);
		if (vertexRep != edgeRep) {
			TreePair.push_back(GraphPair[i]);
			Union(vertexRep, edgeRep);
		}
	}
}

void Graph::printGraph() {
	cout<<"Edge: "<<"Weight: "<<endl;
	for (int i = 0; i < TreePair.size(); i++) {
		cout<<TreePair[i].second.first<<" - "<<TreePair[i].second.second<<" : "<<TreePair[i].first;
		cout<<endl;
	}	
}

int main() {
	Graph g(6);
	g.addEdge(0, 1, 4);
	g.addEdge(0, 2, 4);
	g.addEdge(1, 2, 2);
	g.addEdge(1, 0, 4);
	g.addEdge(2, 0, 4);
	g.addEdge(2, 1, 2);
	g.addEdge(2, 3, 3);
	g.addEdge(2, 5, 2);
	g.addEdge(2, 4, 4);
	g.addEdge(3, 2, 3);
   	g.addEdge(3, 4, 3);
        g.addEdge(4, 2, 4);
        g.addEdge(4, 3, 3);
        g.addEdge(5, 2, 2);
        g.addEdge(5, 4, 3);
        g.Kruskal();
        g.printGraph();
	return 0;
}
