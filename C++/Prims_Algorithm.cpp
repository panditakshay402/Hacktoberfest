#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

// Define a structure to represent edges in the graph
struct Edge {
    int to;
    int weight;
    Edge(int t, int w) : to(t), weight(w) {}
};

// Define a custom comparison function for the priority queue
// to select the edge with the minimum weight
struct CompareEdges {
    bool operator()(const Edge& a, const Edge& b) {
        return a.weight > b.weight;
    }
};

// Function to find the minimum spanning tree using Prim's algorithm
void prim(vector<vector<Edge>>& graph) {
    int n = graph.size(); // Number of vertices
    vector<bool> visited(n, false); // Track visited vertices
    priority_queue<Edge, vector<Edge>, CompareEdges> pq; // Priority queue for edges
    int totalWeight = 0; // Total weight of the minimum spanning tree

    // Start from the first vertex (you can choose any starting vertex)
    pq.push(Edge(0, 0));

    while (!pq.empty()) {
        // Get the edge with the minimum weight
        Edge current = pq.top();
        pq.pop();

        int vertex = current.to;
        int weight = current.weight;

        // If the vertex has already been visited, skip it
        if (visited[vertex]) {
            continue;
        }

        // Mark the vertex as visited
        visited[vertex] = true;
        totalWeight += weight;

        // Output the edge in the minimum spanning tree
        cout << "Add edge: " << vertex << " to " << current.weight << endl;

        // Explore adjacent vertices and add their edges to the priority queue
        for (const Edge& neighbor : graph[vertex]) {
            if (!visited[neighbor.to]) {
                pq.push(neighbor);
            }
        }
    }

    cout << "Total weight of minimum spanning tree: " << totalWeight << endl;
}

int main() {
    int n, m; // Number of vertices and edges
    cin >> n >> m;

    vector<vector<Edge>> graph(n);

    // Read the edges and their weights
    for (int i = 0; i < m; ++i) {
        int u, v, w; // Edge from u to v with weight w
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w); // For undirected graph
    }

    prim(graph);

    return 0;
}
