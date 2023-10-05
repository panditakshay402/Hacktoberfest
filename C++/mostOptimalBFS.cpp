//BFS stands for Breadth First Search. It is a graph traversal algorithm that visits all the vertices of a graph in breadth-first order, i.e., it visits all the vertices at the same level before moving on to the next level. BFS is implemented using a queue data structure.

//The algorithm starts at a given vertex (usually the root) and explores all the vertices at the current level before moving on to the next level. It maintains a queue of vertices that are yet to be explored. The algorithm dequeues a vertex from the queue, explores all its neighbors, and enqueues any unexplored neighbors. This process continues until all the vertices have been explored.

//BFS is useful for finding the shortest path between two vertices in an unweighted graph. It can also be used to detect cycles in a graph and to check if a graph is bipartite.

//In the code provided, the BFS algorithm is implemented using an adjacency list to represent the graph and a boolean array to keep track of visited nodes. The algorithm starts at node 0 and explores all the nodes reachable from it using the BFS traversal. The output of the algorithm is the order in which the nodes are visited.

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Function to perform Breadth First Search (BFS) traversal on a graph
void bfs(vector<int> adj[], int start, bool visited[]) {
    queue<int> q;
    visited[start] = true;
    q.push(start);

    // Loop until all nodes in the graph have been visited
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        cout << curr << " "; // Print the current node

        // Visit all neighbors of the current node
        for (int i = 0; i < adj[curr].size(); i++) {
            int neighbor = adj[curr][i];
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> adj[n]; // Create an adjacency list to represent the graph
    bool visited[n] = {false}; // Create an array to keep track of visited nodes

    // Read in the edges of the graph
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // Add edge from u to v
        adj[v].push_back(u); // Add edge from v to u
    }

    bfs(adj, 0, visited); // Perform BFS traversal starting from node 0

    return 0;
}
