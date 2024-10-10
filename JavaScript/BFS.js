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

    // BFS algorithm
    bfs(startVertex) {
        const visited = new Array(this.numberOfVertices).fill(false); // Mark all vertices as not visited
        const queue = []; // Queue for BFS

        // Start from the given vertex
        visited[startVertex] = true; // Mark the start vertex as visited
        queue.push(startVertex); // Add it to the queue

        while (queue.length > 0) {
            const currentVertex = queue.shift(); // Dequeue a vertex from the queue
            console.log(currentVertex); // Print the current vertex

            // Get all adjacent vertices
            this.adjacencyList[currentVertex].forEach(neighbor => {
                if (!visited[neighbor]) { // Visit all unvisited neighbors
                    visited[neighbor] = true;
                    queue.push(neighbor); // Add the neighbor to the queue
                }
            });
        }
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

// Perform BFS
console.log("Breadth-First Search starting from vertex 0:");
graph.bfs(0);
