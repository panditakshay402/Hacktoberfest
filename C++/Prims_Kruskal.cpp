#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int u, v, weight;
    Edge(int _u, int _v, int _weight) : u(_u), v(_v), weight(_weight) {}
};

// Graph class using adjacency list representation
class Graph {
public:
    int V; // Number of vertices
    vector<vector<pair<int, int>>> adj; // Adjacency list (vertex, weight)

    Graph(int vertices) : V(vertices) {
        adj.resize(V);
    }

    // Add an edge to the graph
    void addEdge(int u, int v, int weight) {
        adj[u].emplace_back(v, weight);
        adj[v].emplace_back(u, weight); // For undirected graph
    }
};

// Function to implement Prim's algorithm for finding MST
void primMST(Graph& graph) {
    vector<bool> inMST(graph.V, false);
    vector<int> key(graph.V, INT_MAX);
    vector<int> parent(graph.V, -1);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int src = 0; // Start from the first vertex
    pq.push({0, src});
    key[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        inMST[u] = true;

        for (auto& neighbor : graph.adj[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    // Print the MST
    cout << "Edges in MST (Prim's Algorithm):\n";
    for (int i = 1; i < graph.V; ++i) {
        cout << "Edge: " << parent[i] << " - " << i << " Weight: " << key[i] << "\n";
    }
}

// Function to implement Kruskal's algorithm for finding MST
void kruskalMST(Graph& graph) {
    int V = graph.V;
    vector<Edge> edges;
    
    // Create a list of edges
    for (int u = 0; u < V; ++u) {
        for (auto& neighbor : graph.adj[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;
            edges.emplace_back(u, v, weight);
        }
    }

    // Sort edges in ascending order by weight
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });

    vector<int> parent(V, -1);
    vector<Edge> MST;

    for (const Edge& edge : edges) {
        int u = edge.u;
        int v = edge.v;
        int weight = edge.weight;

        int parent_u = u;
        int parent_v = v;

        while (parent[parent_u] != -1) {
            parent_u = parent[parent_u];
        }

        while (parent[parent_v] != -1) {
            parent_v = parent[parent_v];
        }

        if (parent_u != parent_v) {
            MST.push_back(edge);
            parent[parent_u] = parent_v;
        }
    }

    // Print the MST
    cout << "Edges in MST (Kruskal's Algorithm):\n";
    for (const Edge& edge : MST) {
        cout << "Edge: " << edge.u << " - " << edge.v << " Weight: " << edge.weight << "\n";
    }
}

int main() {
    int V, E; // Number of vertices and edges
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    Graph graph(V);

    cout << "Enter the edges (u, v, weight):\n";
    for (int i = 0; i < E; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        graph.addEdge(u, v, weight);
    }

    primMST(graph);
    kruskalMST(graph);

    return 0;
}
