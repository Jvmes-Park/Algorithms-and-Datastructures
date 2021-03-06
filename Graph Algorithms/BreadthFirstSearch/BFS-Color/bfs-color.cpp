#include <iostream>
#include <cstdlib>
#include <vector>
#include <list>
#include <queue>

using namespace std;

class Graph {
	private:
		int vertice;
		list<int> *adj;
		vector<string>color;
		vector<int>dist;
		vector<int>parent;
	public:
		Graph(int vertice);
		void addEdge(int source, int destination);
		void BFS(int source, int size);
};

Graph::Graph(int vertice) {
	this -> vertice = vertice;
	adj = new list<int>[vertice];	
}

void Graph::addEdge(int source, int destination) {
	adj[source].push_back(destination);
}

void Graph::BFS(int source, int size) {
	color.assign(size, "white");
	dist.assign(size, 0);
	parent.assign(size, -1);	
	for (int i = 0; i < size; i++) {
		if (color[i] == "white") {
			queue<int>Q;
			Q.push(source);
			dist[source] = 0;
			color[source] = "gray";
			while (!Q.empty()) {
				int u = Q.front();
				Q.pop();
				cout<<u<<" ";
				for (auto i = adj[u].begin(); i != adj[u].end(); i++) {
					if (color[*i] == "white") {
						color[*i] = "gray";
						dist[*i] = dist[u] + 1;
						parent[*i] = u;
						Q.push(*i);
					}
				}
				color[u] = "black";
			}
		}
	}
}

int main() {
	int size = 4;
	Graph g(size);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);
	cout<<"BFS from source 0: "<<endl;
	g.BFS(0, size);
}
