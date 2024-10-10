# Graph class using adjacency list
class Graph:
    def __init__(self, vertices):
        self.numberOfVertices = vertices  # Number of vertices
        self.adjacencyList = [[] for _ in range(vertices)]  # Adjacency list

    # Add edge to the graph
    def add_edge(self, source, destination):
        self.adjacencyList[source].append(destination)  # Add destination to source

    # DFS utility (recursive function)
    def dfs_util(self, current_vertex, visited):
        visited[current_vertex] = True  # Mark the current vertex as visited
        print(current_vertex, end=" ")

        # Visit all unvisited neighbors
        for neighbor in self.adjacencyList[current_vertex]:
            if not visited[neighbor]:
                self.dfs_util(neighbor, visited)

    # DFS traversal method
    def dfs(self, start_vertex):
        visited = [False] * self.numberOfVertices  # Mark all vertices as not visited
        self.dfs_util(start_vertex, visited)  # Call recursive DFS helper function


# Main driver code
graph = Graph(6)

# Add edges to the graph
graph.add_edge(0, 1)
graph.add_edge(0, 2)
graph.add_edge(1, 3)
graph.add_edge(1, 4)
graph.add_edge(2, 4)
graph.add_edge(3, 5)
graph.add_edge(4, 5)

# Perform DFS
print("\nDepth-First Search starting from vertex 0:")
graph.dfs(0)
