// Here’s how you can implement Breadth-First Search (BFS) in C++ using the graph structure

#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <vector>

class Graph {
private:
    // Adjacency list to store the graph
    std::unordered_map<int, std::list<int>> adjList;

public:
    // Function to add an edge between two vertices
    void addEdge(int v1, int v2) {
        adjList[v1].push_back(v2);
        adjList[v2].push_back(v1);  // Since the graph is undirected
    }

    // Function to perform BFS traversal from a given source vertex
    void BFS(int start) {
        // Vector to track visited vertices
        std::vector<bool> visited(adjList.size(), false);
        // Queue to help with the BFS traversal
        std::queue<int> q;

        // Start from the given vertex
        visited[start] = true;
        q.push(start);

        // Continue the BFS until the queue is empty
        while (!q.empty()) {
            // Get the next vertex from the queue
            int v = q.front();
            q.pop();

            std::cout << v << " ";

            // Get all the adjacent vertices of the dequeued vertex
            for (int neighbor : adjList[v]) {
                if (!visited[neighbor]) {
                    // Mark neighbor as visited and enqueue it
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }
};

int main() {
    Graph g;

    // Adding edges
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    // Perform BFS starting from vertex 0
    std::cout << "BFS starting from vertex 0:" << std::endl;
    g.BFS(0);

    return 0;
}