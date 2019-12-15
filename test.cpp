#include <iostream>
#include <vector>
using namespace std;


class digraph {
private:
  // la lista de adyacencias (un vector de vectores de enteros)
  vector< vector< unsigned int > > adj;

  void DFS(int n, vector<bool> &visited) const;

public:
  // constructor que recibe la cantidad de vertices del grafo
  digraph(unsigned int vertexQty) { adj.resize(vertexQty); }

  // añade una arista del nodo u al v
  void addEdge(unsigned int u, unsigned int v);

  // devuelve la cantidad de aristas en el grafo
  int edgeQuantity() const;
  
  void DFS(int n) const;
};

void digraph::addEdge(unsigned int u, unsigned int v) {
  adj[u].push_back(v);
}

int digraph::edgeQuantity() const {
  int sum = 0;
  for (int i = 0; i < adj.size(); i++) {
    sum += adj[i].size();
  }
  return sum;
}

void digraph::DFS(int n, vector<bool> &visited) const {
  if (!visited[n]) {
    visited[n] = 1;
    cout << n << endl;
    for (int i = 0; i < adj[n].size(); i++) {
      DFS(adj[n][i], visited);
    }
  }
}

void digraph::DFS(int n) const {
  vector <bool> visited(adj.size(), 0);
  DFS(n, visited);
}

int main() {
  digraph G(4);

  G.addEdge(0,1);
  G.addEdge(0,2);
  G.addEdge(2,3);
  G.DFS(0);
}