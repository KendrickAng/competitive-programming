import itertools
import subprocess

nodes = 4
edges = []

# generate all possible edges except self-edges
for u in range(nodes):
    for v in range(u+1, nodes):
        if u == v: continue 
        edges.append((u, v))
        edges.append((v, u))

# pick all possible combinations of edges
id = 0
for numEdgesPicked in range(1, len(edges)+1):
    for combination in itertools.combinations(edges, numEdgesPicked):
        nodes = set([node for tuple in combination for node in tuple])

        # create input string
        input_string = f"{numEdgesPicked}\n"
        for u, v in combination:
            input_string += f"{u} {v}\n"
        for node in nodes:
            input_string += f"{node}\n"

        correct = subprocess.run(["./answer.exe"], input=input_string, text=True, capture_output=True)
        test = subprocess.run(["./runningmom.exe"], input=input_string, text=True, capture_output=True)
        if correct.stdout != test.stdout:
            print(input_string)
            print(correct)
            print(test)
            exit(0)

print("success!")
