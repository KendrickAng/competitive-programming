import itertools
import random
import subprocess
from collections import defaultdict

def dfs(node, adjList, visited):
    if node in visited:
        return
    visited.add(node)
    for neigh in adjList[node]:
        if neigh not in visited:
            dfs(neigh, adjList, visited)

def isConnected(edges):
    adjList = defaultdict(list)
    uniqueNodes = set()
    for u, v in edges:
        adjList[u].append(v)
        adjList[v].append(u)
        uniqueNodes.add(u)
        uniqueNodes.add(v)
        start = u
    visited = set()
    dfs(start, adjList, visited)
    if visited != uniqueNodes:
        return False
    return True

def make_input(n, edges):
    ret = [f"{n} {len(edges)}"]
    for u, v in edges:
        ret.append(f"{u+1} {v+1}")
    for _ in range(n):
        ret.append(str(random.randint(0, 10)))
    return "\n".join(ret)
    

for NUM_NODES in range(2, 200000):
    edges = []

    for u in range(NUM_NODES):
        for v in range(u+1, NUM_NODES):
            if u == v: continue
            edges.append((u, v))

    for numEdges in range(NUM_NODES-1, len(edges)+1):
        for pickedEdges in itertools.combinations(edges, numEdges):
            input_string = make_input(NUM_NODES, pickedEdges)

            correct = subprocess.run(["./a.exe"], input=input_string, text=True, capture_output=True)
            test = subprocess.run(["./conquestwrong.exe"], input=input_string, text=True, capture_output=True)
            if correct.stdout != test.stdout:
                print(input_string)
                print("*** EXPECTED ***")
                print(correct.stdout)
                print("*** GOT ***")
                print(test.stdout)
                exit(0)
            # else:
            #     print(f"{correct.stdout}{test.stdout}")