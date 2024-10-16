#include <bits/stdc++.h>
using namespace std;

// Number of vertices in the graph
#define V 9

// A utility function to print the constructed distance
// array
void printSolution(vector<int> &dist)
{
    cout << "\tVertex \t\t\tDistance from Source\n";
    for (int i = 0; i < V; i++)
        cout << "\t" << i << " \t\t\t\t " << dist[i] << endl;
}

// Function that implements Dijkstra's single source shortest path algorithm
void dijkstra(vector<vector<pair<int, int>>> &graph, int src)
{
    // Priority queue to store (distance, vertex) pairs
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Vector to store the shortest distance from source to each vertex
    vector<int> dist(V, INT_MAX);

    // Insert the source node and initialize its distance as 0
    pq.push({0, src});
    dist[src] = 0;

    // While there are vertices left to process
    while (!pq.empty())
    {
        // Extract the vertex with minimum distance value
        int u = pq.top().second;
        pq.pop();

        // Traverse through all adjacent vertices of u
        for (auto &adj : graph[u])
        {
            int v = adj.first;
            int weight = adj.second;

            // If there is a shorter path to v through u
            if (dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    // Print the constructed distance array
    printSolution(dist);
}

// Driver program to test the above function
int main()
{
    // Create a graph with adjacency list representation
    vector<vector<pair<int, int>>> graph(V);

    // Add edges with (vertex, weight) pairs
    graph[0].push_back({1, 4});
    graph[0].push_back({7, 8});
    graph[1].push_back({0, 4});
    graph[1].push_back({2, 8});
    graph[1].push_back({7, 11});
    graph[2].push_back({1, 8});
    graph[2].push_back({3, 7});
    graph[2].push_back({5, 4});
    graph[2].push_back({8, 2});
    graph[3].push_back({2, 7});
    graph[3].push_back({4, 9});
    graph[3].push_back({5, 14});
    graph[4].push_back({3, 9});
    graph[4].push_back({5, 10});
    graph[5].push_back({2, 4});
    graph[5].push_back({3, 14});
    graph[5].push_back({4, 10});
    graph[5].push_back({6, 2});
    graph[6].push_back({5, 2});
    graph[6].push_back({7, 1});
    graph[6].push_back({8, 6});
    graph[7].push_back({0, 8});
    graph[7].push_back({1, 11});
    graph[7].push_back({6, 1});
    graph[7].push_back({8, 7});
    graph[8].push_back({2, 2});
    graph[8].push_back({6, 6});
    graph[8].push_back({7, 7});

    // Call Dijkstra's algorithm
    dijkstra(graph, 0);

    return 0;
}
