import java.util.*;

class BFS {
    private int numberOfVertices; // Number of vertices in the graph
    private LinkedList<Integer>[] adjacencyList; // Array of LinkedLists to store adjacency list representation of the graph

    // Constructor to initialize the graph
    Graph(int vertices) {
        numberOfVertices = vertices; // Set the number of vertices
        adjacencyList = new LinkedList[vertices]; // Create an array of linked lists for each vertex
        for (int i = 0; i < vertices; i++) {
            adjacencyList[i] = new LinkedList<>(); // Initialize each linked list
        }
    }

    // Method to add an edge to the graph (from source to destination)
    void addEdge(int source, int destination) {
        adjacencyList[source].add(destination); // Add destination to the adjacency list of the source vertex
        // For undirected graph, we would also add source to destination's list (adjacencyList[destination].add(source))
    }

    // Method to perform BFS traversal starting from the given startVertex
    void bfs(int startVertex) {
        // Array to track whether a vertex has been visited (initialized to false by default)
        boolean[] visited = new boolean[numberOfVertices];

        // Queue to help with the BFS traversal (FIFO structure)
        Queue<Integer> queue = new LinkedList<>();

        // Start BFS from the given startVertex
        visited[startVertex] = true; // Mark the start vertex as visited
        queue.add(startVertex); // Enqueue the start vertex

        // Continue BFS until the queue is empty
        while (!queue.isEmpty()) {
            // Dequeue the current vertex from the front of the queue
            int currentVertex = queue.poll();
            System.out.print(currentVertex + " "); // Print the current vertex

            // Get all adjacent vertices (neighbors) of the current vertex
            for (int neighbor : adjacencyList[currentVertex]) {
                // If the adjacent vertex hasn't been visited yet
                if (!visited[neighbor]) {
                    visited[neighbor] = true; // Mark it as visited
                    queue.add(neighbor); // Enqueue the vertex to explore it in subsequent iterations
                }
            }
        }
    }

    // Main method to test the BFS implementation
    public static void main(String[] args) {
        // Create a graph with 6 vertices (0 to 5)
        Graph graph = new Graph(6);

        // Add edges to the graph (directed edges)
        graph.addEdge(0, 1); // Edge from vertex 0 to vertex 1
        graph.addEdge(0, 2); // Edge from vertex 0 to vertex 2
        graph.addEdge(1, 3); // Edge from vertex 1 to vertex 3
        graph.addEdge(1, 4); // Edge from vertex 1 to vertex 4
        graph.addEdge(2, 4); // Edge from vertex 2 to vertex 4
        graph.addEdge(3, 5); // Edge from vertex 3 to vertex 5
        graph.addEdge(4, 5); // Edge from vertex 4 to vertex 5

        // Perform BFS starting from vertex 0
        System.out.println("Breadth-First Search starting from vertex 0:");
        graph.bfs(0);
    }
}
