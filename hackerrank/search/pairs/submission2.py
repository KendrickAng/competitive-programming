"""
Two pointer approach - good for finding two numbers that add
up to some number in O(n) in a sorted array
"""
def pairs(k, arr):
    arr.sort()
    i = 0
    j = 1
    count = 0
    while j < len(arr):
        diff = arr[j] - arr[i]
        if diff == k:
            count += 1
            j += 1
        elif diff > k:
            i += 1
        else:
            j += 1
    return count

print(pairs(2, [1,5,3,4,2]))