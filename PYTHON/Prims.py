import heapq

class Graph:
    def __init__(self, vertices):
        self.V = vertices
        self.graph = [[] for _ in range(vertices)]

    def add_edge(self, u, v, weight):
        self.graph[u].append((v, weight))
        self.graph[v].append((u, weight))

    def prim_mst(self):
        visited = [False] * self.V
        min_heap = [(0, 0)]  # (weight, vertex)
        mst_weight = 0

        while min_heap:
            weight, vertex = heapq.heappop(min_heap)

            if visited[vertex]:
                continue

            visited[vertex] = True
            mst_weight += weight

            for neighbor, edge_weight in self.graph[vertex]:
                if not visited[neighbor]:
                    heapq.heappush(min_heap, (edge_weight, neighbor))

        return mst_weight

# Example usage:
if __name__ == "__main__":
    V = 5  # Number of vertices
    graph = Graph(V)
    graph.add_edge(0, 1, 2)
    graph.add_edge(0, 3, 6)
    graph.add_edge(1, 2, 3)
    graph.add_edge(1, 3, 8)
    graph.add_edge(1, 4, 5)
    graph.add_edge(2, 4, 7)
    graph.add_edge(3, 4, 9)

    mst_weight = graph.prim_mst()
    print("Minimum Spanning Tree Weight:", mst_weight)
