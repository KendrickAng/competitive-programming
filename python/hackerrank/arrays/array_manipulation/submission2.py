# Optimal solution - O(m)

# Complete the arrayManipulation function below.
def arrayManipulation(n, queries):
    # initialise the list of n values
    arr = [ 0 for i in range(n) ]

    # loop through each query and mark the array
    for query in queries:
        a, b, k = query
        arr[idx(a)] += k
        arr[idx(b) + 1] += -k

    # apply changes
    sum = 0
    for i in range(len(arr)):
       sum += arr[i]
       arr[i] += sum

    return max(arr)

def idx(oneIndexed):
    return oneIndexed - 1
