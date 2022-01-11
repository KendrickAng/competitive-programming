n = int(input())
students = list(map(int, input().split()))
rooms = [(x, str(i+1)) for i, x in enumerate(students)]
rooms.sort()
rooms.reverse()

issafe = True
tmp = 0
for num, idx in rooms:
    tmp += num
if tmp - rooms[0][0] < rooms[0][0]:
    issafe = False
if issafe:
    ans = [tup[1] for tup in rooms]
    print(" ".join(ans))
else:
    print("impossible")
