#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Graph {
    int numberOfVertices; // Number of vertices
    list<int>* adjacencyList; // Adjacency list

public:
    // Constructor
    Graph(int vertices) {
        numberOfVertices = vertices;
        adjacencyList = new list<int>[vertices];
    }

    // Method to add an edge to the graph
    void addEdge(int source, int destination) {
        adjacencyList[source].push_back(destination); // Add edge from source to destination
    }

    // BFS algorithm
    void bfs(int startVertex) {
        // Create a visited array and initialize all vertices as not visited
        bool* visited = new bool[numberOfVertices];
        for (int i = 0; i < numberOfVertices; i++)
            visited[i] = false;

        // Create a queue for BFS
        queue<int> queue;

        // Mark the current node as visited and enqueue it
        visited[startVertex] = true;
        queue.push(startVertex);

        while (!queue.empty()) {
            // Dequeue a vertex from queue and print it
            int currentVertex = queue.front();
            cout << currentVertex << " ";
            queue.pop();

            // Get all adjacent vertices of the dequeued vertex
            // If an adjacent vertex has not been visited, mark it visited and enqueue it
            for (auto neighbor : adjacencyList[currentVertex]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    queue.push(neighbor);
                }
            }
        }

        delete[] visited; // Free the memory for the visited array
    }
};

int main() {
    Graph graph(6);

    // Add edges to the graph
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 4);
    graph.addEdge(3, 5);
    graph.addEdge(4, 5);

    // Perform BFS from vertex 0
    cout << "Breadth-First Search starting from vertex 0:\n";
    graph.bfs(0);

    return 0;
}
