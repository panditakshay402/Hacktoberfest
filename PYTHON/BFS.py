from collections import deque

# Graph class using adjacency list
class Graph:
    def __init__(self, vertices):
        self.numberOfVertices = vertices  # Number of vertices
        self.adjacencyList = [[] for _ in range(vertices)]  # Adjacency list

    # Add edge to the graph
    def add_edge(self, source, destination):
        self.adjacencyList[source].append(destination)  # Add destination to source

    # BFS algorithm
    def bfs(self, start_vertex):
        visited = [False] * self.numberOfVertices  # Mark all vertices as not visited
        queue = deque()  # Use deque as a queue

        # Start from the given vertex
        visited[start_vertex] = True  # Mark the start vertex as visited
        queue.append(start_vertex)  # Add it to the queue

        while queue:
            current_vertex = queue.popleft()  # Dequeue a vertex from the queue
            print(current_vertex, end=" ")

            # Get all adjacent vertices
            for neighbor in self.adjacencyList[current_vertex]:
                if not visited[neighbor]:  # Visit all unvisited neighbors
                    visited[neighbor] = True
                    queue.append(neighbor)


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

# Perform BFS
print("Breadth-First Search starting from vertex 0:")
graph.bfs(0)
