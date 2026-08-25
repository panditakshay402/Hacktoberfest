# Python program for implementation of Dijkstra's shortest path algorithm
import heapq


class Graph:
    def __init__(self, vertices):
        self.V = vertices
        self.graph = [[] for _ in range(vertices)]

    def add_edge(self, u, v, weight):
        # Undirected edge; drop the second append for a directed graph
        self.graph[u].append((v, weight))
        self.graph[v].append((u, weight))

    def dijkstra(self, source):
        # dist[v] is the best known distance from source to v
        dist = [float('inf')] * self.V
        dist[source] = 0

        # parent[v] lets us rebuild the actual path afterwards
        parent = [-1] * self.V

        visited = [False] * self.V
        min_heap = [(0, source)]  # (distance, vertex)

        while min_heap:
            d, vertex = heapq.heappop(min_heap)

            # A shorter route to this vertex was already settled
            if visited[vertex]:
                continue

            visited[vertex] = True

            for neighbor, edge_weight in self.graph[vertex]:
                new_dist = d + edge_weight

                # Found a cheaper way to reach the neighbor
                if new_dist < dist[neighbor]:
                    dist[neighbor] = new_dist
                    parent[neighbor] = vertex
                    heapq.heappush(min_heap, (new_dist, neighbor))

        return dist, parent

    def shortest_path(self, source, target):
        dist, parent = self.dijkstra(source)

        # Target was never reached
        if dist[target] == float('inf'):
            return float('inf'), []

        # Walk the parent pointers backwards from target to source
        path = []
        node = target
        while node != -1:
            path.append(node)
            node = parent[node]
        path.reverse()

        return dist[target], path


# Driver Code
if __name__ == '__main__':
    g = Graph(6)
    g.add_edge(0, 1, 4)
    g.add_edge(0, 2, 1)
    g.add_edge(2, 1, 2)
    g.add_edge(1, 3, 5)
    g.add_edge(2, 3, 8)
    g.add_edge(3, 4, 3)
    g.add_edge(4, 5, 1)

    source = 0
    dist, _ = g.dijkstra(source)

    print("Shortest distances from vertex", source)
    for vertex in range(g.V):
        print("  vertex", vertex, "->", dist[vertex])

    cost, path = g.shortest_path(0, 5)
    print("\nCheapest route from 0 to 5 costs", cost)
    print("Path:", " -> ".join(str(v) for v in path))
