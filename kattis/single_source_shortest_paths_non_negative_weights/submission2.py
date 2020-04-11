from queue import PriorityQueue

INFINITY = 9999999

class Graph:
    def __init__(self, num_nodes):
        self.num_nodes = num_nodes
        self.adjList = {idx:set() for idx in range(num_nodes)}

    def connect(self, u, v, weight):
        self.adjList[u].add((v, weight))

    def djikstras(self):
        """
        Outputs a distance array of size |num_nodes|.
        """
        D = [INFINITY] * self.num_nodes
        D[start] = 0
        pq = PriorityQueue()
        pq.put((0, start))

        while not pq.empty():
            D_u, u = pq.get()

            # important check, lazy DS
            if D_u == D[u]:
                for v, D_uv in self.adjList[u]:
                    if D_u + D_uv < D[v]:
                        D[v] = D_u + D_uv
                        pq.put((D[v], v))

        return D


if __name__ == '__main__':
    # num_nodes, num_edges, num_queries, start_node_idx
    while True:
        nodes, edges, queries, start = map(int, input().split())
        if nodes == 0 and edges == 0 and queries == 0 and start == 0:
            break

        graph = Graph(nodes)
        for _ in range(edges):
            u, v, weight = map(int, input().split())
            graph.connect(u, v, weight)

        distances = graph.djikstras()

        for _ in range(queries):
            query = int(input())
            if distances[query] >= INFINITY:
                print("Impossible")
            else:
                print(distances[query])

        print()