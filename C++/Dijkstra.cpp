#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii; // pair to represent (distance, node)

// Dijkstra's Algorithm
void dijkstra(int source, vector<vector<pii>>& adjList, int V) {
    // Min-heap priority queue to store (distance, vertex)
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    // Vector to store shortest distances initialized to infinity
    vector<int> dist(V, INT_MAX);

    // Start with the source node, distance = 0
    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second; // Get the node with the smallest distance
        pq.pop();

        // Traverse all adjacent vertices of the current node
        for (auto edge : adjList[u]) {
            int v = edge.second;  // Adjacent node
            int weight = edge.first;  // Edge weight

            // Relaxation step
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    // Output shortest distances
    cout << "Shortest distances from source " << source << ":\n";
    for (int i = 0; i < V; ++i) {
        cout << "Vertex " << i << " -> Distance: " << dist[i] << endl;
    }
}

int main() {
    int V = 5; // Number of vertices
    vector<vector<pii>> adjList(V);

    // Add edges (weight, node)
    adjList[0].push_back({10, 1});
    adjList[0].push_back({5, 3});
    adjList[1].push_back({1, 2});
    adjList[1].push_back({2, 3});
    adjList[2].push_back({4, 4});
    adjList[3].push_back({3, 2});
    adjList[3].push_back({9, 4});
    adjList[4].push_back({7, 0});

    int source = 0;
    dijkstra(source, adjList, V);

    return 0;
}
