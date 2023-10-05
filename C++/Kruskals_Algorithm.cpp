#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define a structure to represent edges in the graph
struct Edge {
    int from;
    int to;
    int weight;
    Edge(int u, int v, int w) : from(u), to(v), weight(w) {}
};

// Define a custom comparison function to sort edges by weight
bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

// Function to find the minimum spanning tree using Kruskal's algorithm
void kruskal(vector<Edge>& edges, int numVertices) {
    vector<Edge> minimumSpanningTree; // Stores the edges of the minimum spanning tree
    vector<int> parent(numVertices); // Parent array for disjoint-set data structure

    // Initialize each vertex as its own parent (initially disjoint sets)
    for (int i = 0; i < numVertices; ++i) {
        parent[i] = i;
    }

    // Sort edges in ascending order of weight
    sort(edges.begin(), edges.end(), compareEdges);

    for (const Edge& edge : edges) {
        int rootA = find(parent, edge.from);
        int rootB = find(parent, edge.to);

        // Check if adding this edge forms a cycle
        if (rootA != rootB) {
            minimumSpanningTree.push_back(edge);
            unionSets(parent, rootA, rootB);
        }
    }

    // Output the edges in the minimum spanning tree
    for (const Edge& edge : minimumSpanningTree) {
        cout << "Edge: " << edge.from << " - " << edge.to << " | Weight: " << edge.weight << endl;
    }
}

// Function to find the root of a set (used in the disjoint-set data structure)
int find(vector<int>& parent, int vertex) {
    if (parent[vertex] != vertex) {
        // Recursively find the root
        parent[vertex] = find(parent, parent[vertex]);
    }
    return parent[vertex];
}

// Function to union two sets (used in the disjoint-set data structure)
void unionSets(vector<int>& parent, int rootA, int rootB) {
    parent[rootA] = rootB;
}

int main() {
    int numVertices, numEdges; // Number of vertices and edges
    cin >> numVertices >> numEdges;

    vector<Edge> edges;

    // Read the edges and their weights
    for (int i = 0; i < numEdges; ++i) {
        int from, to, weight; // Edge from 'from' to 'to' with weight 'weight'
        cin >> from >> to >> weight;
        edges.push_back(Edge(from, to, weight));
    }

    kruskal(edges, numVertices);

    return 0;
}
