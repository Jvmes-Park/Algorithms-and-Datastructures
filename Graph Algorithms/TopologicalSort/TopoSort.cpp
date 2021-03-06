#include <iostream>
#include <list>
#include <cstdlib>
#include <stack>
using namespace std;

class Graph {
	private:
		int vertice;
		list<int> *adj;
		stack<int> Stack;
	public:
		Graph(int vertice);
		void addEdge(int source, int destination);
		void DFS(int vertex, bool visited[], stack<int> &Stack);
		void TopoSort();
};

Graph::Graph(int vertice) {
	this -> vertice = vertice;
	adj = new list<int>[vertice];	
}

void Graph::addEdge(int source, int destination) {
	adj[source].push_back(destination);
}

void Graph::DFS(int vertex, bool visited[], stack<int> &Stack) {
	visited[vertex] = true;
	list<int>::iterator i;
	for (i = adj[vertex].begin(); i != adj[vertex].end(); i++) {
		if (!visited[*i])
			DFS(*i, visited, Stack);
	}
	Stack.push(vertex);
}

void Graph::TopoSort() {
	stack<int> Stack;
	bool* visited = new bool[vertice];
	for (int i = 0; i < vertice; i++) 
		visited[i] = false;
	for (int i = 0; i < vertice; i++)
		if (visited[i] == false)
			DFS(i, visited, Stack);
	while (Stack.empty() == false) {
		cout<<Stack.top()<<" ";
		Stack.pop();
	}
}

int main() {
	Graph g(6);
	g.addEdge(5, 2);
	g.addEdge(5, 0);
	g.addEdge(4, 0);
	g.addEdge(4, 1);
	g.addEdge(2, 3);
	g.addEdge(3, 1);
	cout<<"Topological Sort result: "<<endl;
	g.TopoSort();
}
