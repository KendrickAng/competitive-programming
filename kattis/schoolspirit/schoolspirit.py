n = int(input())
students = []
for _ in range(n):
    students.append(int(input()))

# group score
score = 0
for i in range(len(students)):
    s = students[i]
    score += s * (4/5) ** i
print(score / 5)

# average score
total = 0
for i in range(len(students)):
    tmp = 0
    new = students[:i] + students[i+1:]
    for j in range(len(new)):
        s = new[j]
        tmp += s * (4/5) ** j
    total += 1/5 * tmp
print(total / n)