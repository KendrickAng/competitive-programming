r, c = list(map(int, input().split()))

while r != 0 and c != 0:
    matrix = []
    for _ in range(r):
        matrix.append([c for c in input()])

    # generate the actual words
    words = []
    for i in range(c):
        word = "".join([matrix[ri][i] for ri in range(r)])
        words.append(word)

    words.sort(key=lambda x: x.lower())

    for c in range(len(words)):
        for r in range(len(words[0])):
            matrix[r][c] = words[c][r]

    for arr in matrix:
        print("".join(arr))

    r, c = list(map(int, input().split()))
    if r != 0 and c != 0:
        print()