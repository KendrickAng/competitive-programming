import subprocess

with open("gen.txt") as file:
    for line in file:
        # a, b = map(str, line.split())
        correct = subprocess.run(["./answer.exe"], input=line, text=True, capture_output=True)
        test = subprocess.run(["./a.exe"], input=line, text=True, capture_output=True)
        if correct.stdout != test.stdout:
            print(line)
            print("*** EXPECTED ***")
            print(correct.stdout)
            print("*** GOT ***")
            print(test.stdout)
            # exit(0)
