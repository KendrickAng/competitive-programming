from collections import defaultdict

r = int(input())
sven = [x for x in input()]
n = int(input())
friends = []
for _ in range(n):
    friends.append([x for x in input()])
actual = 0
largest = 0
for i in range(r):
    # calculate actual score
    a = sven[i]
    stats = {"R": 0, "P": 0, "S": 0}
    for friend in friends:
        b = friend[i]
        stats[b] += 1
        if a == "S":
            if b == "P":
                actual += 2
            elif b == "S":
                actual += 1
        elif a == "P":
            if b == "R":
                actual += 2
            elif b == "P":
                actual += 1
        elif a == "R":
            if b == "S":
                actual += 2
            elif b == "R":
                actual += 1
    # calculate largest score
    paper = 2 * stats["R"] + stats["P"]
    rock = 2 * stats["S"] + stats["R"]
    scissors = 2 * stats["P"] + stats["S"]
    largest += max([paper, scissors, rock])


print(actual)
print(largest)