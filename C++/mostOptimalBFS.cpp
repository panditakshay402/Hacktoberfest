// Breadth-First Search (BFS) is a graph traversal algorithm that explores all the vertices of a graph in breadthward motion, i.e., it explores all the vertices at the current level before moving on to the vertices at the next level. BFS is typically used to find the shortest path from a source vertex to all other vertices in an unweighted graph. It can also be used to solve various graph-related problems.

// Here's a step-by-step explanation of the BFS algorithm, followed by a C++ code implementation for an unweighted graph:

// BFS Algorithm Explanation:

// Create a queue (usually implemented using a data structure like std::queue in C++).
// Start from the source vertex and enqueue it into the queue.
// Mark the source vertex as visited.
// While the queue is not empty, do the following:
// a. Dequeue a vertex from the front of the queue (let's call it the current vertex).
// b. Visit the current vertex (print it or process it as needed).
// c. For each adjacent vertex of the current vertex that has not been visited yet, enqueue it into the queue and mark it as visited.
// The process continues until the queue is empty, which means all reachable vertices have been visited.
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
public:
    Graph(int numVertices);
    void addEdge(int v, int w);
    void BFS(int startVertex);

private:
    int numVertices;
    vector<vector<int>> adjacencyList;
};

Graph::Graph(int numVertices) {
    this->numVertices = numVertices;
    adjacencyList.resize(numVertices);
}

void Graph::addEdge(int v, int w) {
    adjacencyList[v].push_back(w);
}

void Graph::BFS(int startVertex) {
    vector<bool> visited(numVertices, false);
    queue<int> q;

    visited[startVertex] = true;
    q.push(startVertex);

    while (!q.empty()) {
        int currentVertex = q.front();
        cout << currentVertex << " ";
        q.pop();

        for (int neighbor : adjacencyList[currentVertex]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    Graph g(8);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 6);
    g.addEdge(3, 7);

    cout << "BFS starting from vertex 0: ";
    g.BFS(0);

    return 0;
}
