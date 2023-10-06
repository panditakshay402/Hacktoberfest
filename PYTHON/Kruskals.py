class Graph:
    def __init__(self, vertices):
        self.V = vertices
        self.edges = []

    def add_edge(self, u, v, weight):
        self.edges.append((u, v, weight))

    def kruskal_mst(self):
        self.edges.sort(key=lambda edge: edge[2])  # Sort edges by weight in ascending order
        parent = [-1] * self.V
        mst = []

        def find_set(v):
            if parent[v] == -1:
                return v
            return find_set(parent[v])

        def union_sets(a, b):
            root_a = find_set(a)
            root_b = find_set(b)
            if root_a != root_b:
                parent[root_a] = root_b

        for edge in self.edges:
            u, v, weight = edge
            if find_set(u) != find_set(v):
                mst.append(edge)
                union_sets(u, v)

        mst_weight = sum(edge[2] for edge in mst)
        return mst, mst_weight

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

    mst_edges, mst_weight = graph.kruskal_mst()
    
    print("Minimum Spanning Tree Edges:")
    for edge in mst_edges:
        print(edge[0], "-", edge[1], ":", edge[2])

    print("Minimum Spanning Tree Weight:", mst_weight)
