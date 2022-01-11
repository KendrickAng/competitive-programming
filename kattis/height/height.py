p = int(input())
for _ in range(p):
    tokens = list(map(int, input().split()))
    k, students = tokens[0], tokens[1:]
    pq = []
    ans = 0
    for student in students:
        pq.sort()
        count = 0
        for s in pq:
            if s > student:
                break
            count += 1
        ans += len(pq) - count
        pq.append(student)

    print(f"{k} {ans}")
