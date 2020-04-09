class Node:
    def __init__(self, index, color):
        self.index = index
        self.color = color
        self.neighbours = set()
    def addUndirectedEdge(self, other):
        self.neighbours.add(other)
        other.neighbours.add(self)

def findShortest(graph_nodes, graph_from, graph_to, ids, val):
    """
    Assume that 10^8 operations per second are allowed.
    """
    # First find the number of nodes of color val. If <= 1, no solution.
    nodes = {}
    same_color = [] # ids of nodes with same color as val
    num_matching = 0
    for i, colorId in enumerate(ids):
        nodes[i + 1] = Node(i + 1, colorId)
        if colorId == val:
            same_color.append(i + 1)
            num_matching += 1

    if num_matching <= 1:
        return -1

    # generate graph
    for start, end in zip(graph_from, graph_to):
        nodes[start].addUndirectedEdge(nodes[end])

    # BFS for each node
    from queue import Queue
    shortest_dist = 10000000
    for start_node_id in same_color:
        queue = Queue()
        queue.put(nodes[start_node_id])
        dist = -1
        visited = [False] * (graph_nodes + 1)
        visited[start_node_id] = True

        while not queue.empty():
            curr = queue.get()
            dist += 1

            for neighbour in curr.neighbours:
                if visited[neighbour.index]:
                    continue
                if neighbour.color == val:
                    shortest_dist = min(shortest_dist, dist + 1)
                visited[neighbour.index] = True
                queue.put(neighbour)

    return shortest_dist

graph_nodes = 5
graph_from = [1, 1, 2, 3]
graph_to = [2, 3, 4, 5]
ids = [1, 2, 3, 3, 2]
val = 2
print(findShortest(graph_nodes, graph_from, graph_to, ids, val))
