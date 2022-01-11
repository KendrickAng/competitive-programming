import itertools
import random
import subprocess

NUM_NODES = 3
WEIGHT_MIN = -10
WEIGHT_MAX = 10

edges = []

def make_input(n, m, edges) -> str:
    queries = []
    for u in range(n):
        for v in range(n):
            queries.append((u, v))

    ret = []
    ret.append(f"{n} {m} {len(queries)}")

    # append edges
    for u, v, weight in edges:
        ret.append(f"{u} {v} {weight}")

    # append queries
    for u, v in queries:
        ret.append(f"{u} {v}")
    
    ret.append(f"0 0 0")
    return "\n".join(ret)

# generate all possible edges, even self-edges
for u in range(NUM_NODES):
    for v in range(u+1, NUM_NODES):
        if u == v: continue
        weight = random.randint(WEIGHT_MIN, WEIGHT_MAX)
        edges.append((u, v, weight))
        edges.append((v, u, weight))

# pick edges
id = 0
for numEdges in range(1, len(edges)+1):
    for pickedEdges in itertools.combinations(edges, numEdges):
        input_string = make_input(NUM_NODES, numEdges, pickedEdges)

        correct = subprocess.run(["./answer.exe"], input=input_string, text=True, capture_output=True)
        test = subprocess.run(["./a.exe"], input=input_string, text=True, capture_output=True)
        if correct.stdout != test.stdout:
            print(input_string)
            print("*** EXPECTED ***")
            print(correct.stdout)
            print("*** GOT ***")
            print(test.stdout)
            exit(0)
