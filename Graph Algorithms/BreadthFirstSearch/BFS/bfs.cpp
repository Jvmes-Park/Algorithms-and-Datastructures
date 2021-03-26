#include <iostream>
#include <list>
using namespace std;

class Graph {
	private:
		int vertice;
		list<int> *adj;
	public:
		Graph(int vertice);
		void addEdge(int source, int destination);
		void BFS(int source);
};

Graph::Graph(int vertice) {
	this -> vertice = vertice;
	adj = new list<int>[vertice];
}

void Graph::addEdge(int source, int destination) {
	adj[source].push_back(destination);
}

void Graph::BFS(int source) {
	bool *visited = new bool[vertice];
	for (int i = 0; i < vertice; i++)
		visited[i] = false;
	list<int>queue;
	visited[source] = true;
	queue.push_back(source);
	list<int>::iterator i;
	while(!queue.empty()) {
		source = queue.front();
		cout << source << " ";
		queue.pop_front();
		
		for (i = adj[source].begin(); i != adj[source].end(); i++) {
			if (!visited[*i]) {
			visited[*i] = true;
			queue.push_back(*i);

			}
		}
	}
}


int main() {
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);
	cout<<"BFS from source 0: "<<endl;
	g.BFS(0);
}

