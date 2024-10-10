// Graph class using adjacency list
class Graph {
    constructor(vertices) {
        this.numberOfVertices = vertices; // Number of vertices
        this.adjacencyList = new Array(vertices).fill(null).map(() => []); // Initialize adjacency list
    }

    // Add edge to the graph
    addEdge(source, destination) {
        this.adjacencyList[source].push(destination); // Add destination to source
    }

    // DFS utility (recursive function)
    dfsUtil(currentVertex, visited) {
        visited[currentVertex] = true; // Mark the current vertex as visited
        console.log(currentVertex); // Print the current vertex

        // Visit all unvisited neighbors
        this.adjacencyList[currentVertex].forEach(neighbor => {
            if (!visited[neighbor]) {
                this.dfsUtil(neighbor, visited); // Recursive call for DFS
            }
        });
    }

    // DFS traversal method
    dfs(startVertex) {
        const visited = new Array(this.numberOfVertices).fill(false); // Mark all vertices as not visited
        this.dfsUtil(startVertex, visited); // Call recursive DFS helper function
    }
}

// Main driver code
const graph = new Graph(6);

// Add edges to the graph
graph.addEdge(0, 1);
graph.addEdge(0, 2);
graph.addEdge(1, 3);
graph.addEdge(1, 4);
graph.addEdge(2, 4);
graph.addEdge(3, 5);
graph.addEdge(4, 5);

// Perform DFS
console.log("Depth-First Search starting from vertex 0:");
graph.dfs(0);
