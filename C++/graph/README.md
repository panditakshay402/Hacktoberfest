Explanation:
Graph class: This class uses an adjacency list (unordered map of lists) to store the graph.
addEdge function: Adds an edge between two vertices v1 and v2. Since it’s an undirected graph, the edge is bidirectional.
displayGraph function: Iterates through the adjacency list and prints out the graph structure.

Explanation:
DFSUtil: A recursive helper function that does the actual DFS traversal. It takes the current vertex (v) and the visited vector as arguments.
It marks the current vertex as visited and prints it.
Then it recursively visits all unvisited neighbors.
DFS function: The function that initiates the DFS traversal. It creates a visited vector (initialized to false) to track which nodes have been visited. It then calls DFSUtil for the starting vertex.
Output:
If you run the code, the output will be a DFS traversal of the graph starting from vertex 0, such as:
