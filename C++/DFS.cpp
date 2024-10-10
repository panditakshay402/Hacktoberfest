#include <iostream>
#include <list>
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

    // DFS utility function (recursive)
    void dfsUtil(int currentVertex, bool visited[]) {
        // Mark the current vertex as visited and print it
        visited[currentVertex] = true;
        cout << currentVertex << " ";

        // Recur for all the vertices adjacent to this vertex
        for (auto neighbor : adjacencyList[currentVertex]) {
            if (!visited[neighbor]) {
                dfsUtil(neighbor, visited); // Recursive call to visit the next vertex
            }
        }
    }

    // DFS traversal starting from a given vertex
    void dfs(int startVertex) {
        // Create a visited array and initialize all vertices as not visited
        bool* visited = new bool[numberOfVertices];
        for (int i = 0; i < numberOfVertices; i++)
            visited[i] = false;

        // Call the recursive helper function for DFS
        dfsUtil(startVertex, visited);

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

    // Perform DFS from vertex 0
    cout << "Depth-First Search starting from vertex 0:\n";
    graph.dfs(0);

    return 0;
}
