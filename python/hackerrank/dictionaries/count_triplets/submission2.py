def countTriplets(arr, r):
    """
    Keep two dicts, one to hold elements with indices less than current element, other to hold
    elements with indices greater than current element.
    Do a one pass, then at each stage change the right and left dicts accordingly.
    """
    from collections import defaultdict
    left = defaultdict(int)
    right = defaultdict(int)
    for i, num in enumerate(arr):
        right[num] += 1

    total = 0
    for i, num in enumerate(arr):
        # update tables
        if i == 0:
            right[num] -= 1
            continue

        right[num] -= 1
        left[arr[i-1]] += 1

        left_count, right_count = 0, 0
        if num / r in left:
            left_count = left[num//r]
        if num * r in right:
            right_count = right[num*r]
        total += left_count * right_count
    return total

print(countTriplets([1,4,16,64], 4))
print(countTriplets([1,3,9,9,27,81], 3))


