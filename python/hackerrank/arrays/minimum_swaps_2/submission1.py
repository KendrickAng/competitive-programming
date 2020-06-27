def minimumSwaps(arr):
    ansDict = { i:v for i,v in enumerate(sorted(arr)) }
    lookupDict = { v:i for i,v in enumerate(arr) }
    swaps = 0
    for i,v in enumerate(arr):
        sortedVal = ansDict[i]
        currIdxOfVal = lookupDict[sortedVal]
        if v != sortedVal:
            swaps += 1
            # swap array elements and update lookup dict
            arr[i] = sortedVal
            arr[currIdxOfVal] = v
            lookupDict[sortedVal] = i
            lookupDict[v] = currIdxOfVal
    return swaps


print(minimumSwaps([4,3,1,2]))
print(minimumSwaps([2,3,4,1,5]))