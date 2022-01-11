import subprocess
import random
import itertools

nodes = ["English", "a", "b", "c"]
n = len(nodes) - 1

# make edges
edges = []
for i in range(len(nodes)):
    for j in range(i+1, len(nodes)):
        edges.append((nodes[i], nodes[j], random.randint(1, 10)))

for i in range(1, len(edges)+1):
    for picked in itertools.combinations(edges, i):
        lines = []
        lines.append(f"{len(nodes)-1} {len(picked)}")
        lines.append(" ".join(nodes[1:]))
        for a, b, weight in picked:
            lines.append(f"{a} {b} {weight}")

        input_string = "\n".join(lines)
        correct = subprocess.run(["./answer.exe"], input=input_string, text=True, capture_output=True)
        test = subprocess.run(["./a.exe"], input=input_string, text=True, capture_output=True)

        if (correct.stdout != test.stdout):
            print(f"correct: {correct.stdout}")
            print(f"got: {test.stdout}")
            print(input_string)
            exit(0)