# Brute force - O(nm) runtime

# Complete the arrayManipulation function below.
def arrayManipulation(n, queries):
    # initialise the list of n values
    arr = [ 0 for i in range(n) ]

    # loop through each query and update the array
    for query in queries:
        a, b, k = query
        for i in range(idx(a), idx(b)+1):
            arr[i] += k

    return max(arr)

def idx(oneIndexed):
    return oneIndexed - 1

