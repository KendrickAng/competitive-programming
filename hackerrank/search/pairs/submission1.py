def pairs(k, arr):
    s = set(arr)
    pairs = 0
    for num in arr:
        candidate1 = num + k
        candidate2 = num - k
        if candidate1 in s:
            pairs += 1
        if candidate2 in s:
            pairs += 1
    return pairs // 2


print(pairs(2, [1,5,3,4,2]))