import java.util.*;

class DFS {
    private int numberOfVertices; // Number of vertices in the graph
    private LinkedList<Integer>[] adjacencyList; // Adjacency list to store the graph

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
        // For undirected graph, you can add the reverse edge (adjacencyList[destination].add(source))
    }

    // DFS traversal using recursion
    void dfs(int startVertex) {
        // Create a visited array to keep track of visited vertices
        boolean[] visited = new boolean[numberOfVertices];

        // Call the recursive helper function to perform DFS
        dfsUtil(startVertex, visited);
    }

    // Helper method for DFS traversal
    private void dfsUtil(int currentVertex, boolean[] visited) {
        // Mark the current vertex as visited and print it
        visited[currentVertex] = true;
        System.out.print(currentVertex + " ");

        // Recursively visit all the adjacent vertices (neighbors) of the current vertex
        for (int neighbor : adjacencyList[currentVertex]) {
            if (!visited[neighbor]) {
                dfsUtil(neighbor, visited); // Recursive call to visit the next vertex
            }
        }
    }

    public static void main(String[] args) {
        Graph graph = new Graph(6);

        // Add edges to the graph
        graph.addEdge(0, 1);
        graph.addEdge(0, 2);
        graph.addEdge(1, 3);
        graph.addEdge(1, 4);
        graph.addEdge(2, 4);
        graph.addEdge(3, 5);
        graph.addEdge(4, 5);

        // Perform DFS from vertex 0
        System.out.println("Depth-First Search starting from vertex 0:");
        graph.dfs(0);
    }
}
