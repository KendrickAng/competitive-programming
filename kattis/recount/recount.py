import sys
from collections import defaultdict

votes = defaultdict(int)

for line in sys.stdin:
    if line == "***":
        break
    votes[line] += 1

maxVotes = max(votes.values())

runoff = False
candidate = None
for name, voteCount in votes.items():
    if voteCount == maxVotes and candidate is not None:
        runoff = True
        break
    elif voteCount == maxVotes:
        candidate = name

if runoff:
    print("Runoff!")
else:
    print(candidate)
