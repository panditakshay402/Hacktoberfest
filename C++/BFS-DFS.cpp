#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
private:
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list representation

public:
    Graph(int vertices);
    void addEdge(int v, int w);
    void BFS(int startVertex);
    void DFS(int startVertex);
    void DFSUtil(int v, vector<bool>& visited);
};

Graph::Graph(int vertices) {
    this->V = vertices;
    adj.resize(vertices);
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

void Graph::BFS(int startVertex) {
    vector<bool> visited(V, false);
    queue<int> q;

    visited[startVertex] = true;
    q.push(startVertex);

    while (!q.empty()) {
        int current = q.front();
        cout << current << " ";
        q.pop();

        for (int neighbor : adj[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}

void Graph::DFSUtil(int v, vector<bool>& visited) {
    visited[v] = true;
    cout << v << " ";

    for (int neighbor : adj[v]) {
        if (!visited[neighbor]) {
            DFSUtil(neighbor, visited);
        }
    }
}

void Graph::DFS(int startVertex) {
    vector<bool> visited(V, false);
    DFSUtil(startVertex, visited);
    cout << endl;
}

int main() {
    Graph g(6);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 5);

    cout << "BFS starting from vertex 0: ";
    g.BFS(0);

    cout << "DFS starting from vertex 0: ";
    g.DFS(0);

    return 0;
}
