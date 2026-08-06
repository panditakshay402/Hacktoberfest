//Here’s a simple implementation of a graph data structure in C++ using an adjacency list:

#include <iostream>
#include <unordered_map>
#include <list>

// Graph class representing an undirected graph
class Graph {
private:
    // Adjacency list to store the graph
    std::unordered_map<int, std::list<int>> adjList;

public:
    // Function to add an edge between two vertices
    void addEdge(int v1, int v2) {
        adjList[v1].push_back(v2);  // Add v2 to v1's adjacency list
        adjList[v2].push_back(v1);  // Add v1 to v2's adjacency list (undirected graph)
    }

    // Function to display the graph
    void displayGraph() {
        for (const auto& vertex : adjList) {
            std::cout << vertex.first << ": ";
            for (const auto& neighbor : vertex.second) {
                std::cout << neighbor << " ";
            }
            std::cout << std::endl;
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

    // Displaying the graph
    std::cout << "Graph Adjacency List:" << std::endl;
    g.displayGraph();

    return 0;
}