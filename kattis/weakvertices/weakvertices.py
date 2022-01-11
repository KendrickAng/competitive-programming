n = int(input())
while n != -1:
    matrix = []
    weak = []
    for _ in range(n):
        matrix.append(list(map(int, input().split())))
    
    if n == 1:
        print("0")
    elif n == 2:
        print("0 1")
    else:
        for r in range(len(matrix)):
            has_strong = False
            for c1 in range(len(matrix[0])):
                for c2 in range(c1+1, len(matrix[0])):
                    if matrix[r][c1] == 1 and matrix[r][c2] == 1 and matrix[c1][c2] == 1:
                        has_strong = True
            if not has_strong:
                weak.append(r)
        print(" ".join([str(x) for x in weak]))

    n = int(input())