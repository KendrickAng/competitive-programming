import math
from queue import PriorityQueue

class Node:
    def __init__(self, index):
        self.index = index
        self.neighbours = {}
    def addDirectedEdge(self, v, weight):
        self.neighbours[v] = weight

if __name__ == '__main__':
    # num_nodes, num_edges, num_queries, start_node_idx
    first = True

    while True:
        n, m, q, s = map(int, input().split())
        if n == 0 and m == 0 and q == 0 and s == 0:
            break

        if first:
            first = False
        else:
            print()

        # generate graph
        graph = {i:Node(i) for i in range(0, n)}
        for _ in range(m):
            u, v, w = map(int, input().split())
            graph[u].addDirectedEdge(v, w)

        # run dijkstras
        dist = [math.inf] * n
        dist[s] = 0
        solved = set()
        pq = PriorityQueue()
        pq.put((0, s))

        while not pq.empty():
            dist_to_curr, curr = pq.get()
            solved.add(curr)

            for neighbour in graph[curr].neighbours.keys():
                if neighbour in solved:
                    continue
                # Relax outgoing edges
                if dist[neighbour] > dist_to_curr + graph[curr].neighbours[neighbour]:
                    dist[neighbour] = dist_to_curr + graph[curr].neighbours[neighbour]
                    pq.put((dist[neighbour], neighbour))

        # q queries
        for _ in range(0, q):
            query = int(input())
            if dist[query] >= math.inf:
                print("Impossible")
            else:
                print(dist[query])
