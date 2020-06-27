def countTriplets(arr, r):
    """
    Return the number of triplets of consecutive geometric sum numbers. Order of the three
    numbers must be as in the original array.
    """
    if r <= 1:
        return 0
    
    # create dict for quick lookup
    indices_lookup = {}
    triplets = set()

    for i, num in enumerate(arr):
        if num not in indices_lookup:
            indices_lookup[num] = [i]
        else:
            indices_lookup[num] += [i]

    #print(indices_lookup)
    # loop through each element and find number of next two numbers.
    for num in arr:
        # If they both exist, generate all possible triplets
        if num*r in indices_lookup and num*r*r in indices_lookup:
            for a in indices_lookup[num]:
                for b in indices_lookup[num*r]:
                    if b < a:
                        continue
                    for c in indices_lookup[num*r*r]:
                        if c < b or c < a:
                            continue
                        triplets.add((a,b,c))
    # filter out invalid triplets
    for triplet in triplets:
        a, b, c = triplet
        if a > b or a > c or b > c:
            triplets.remove(triplet)

    # return number of triplets
    return len(triplets)

print(countTriplets([1,4,16,64], 4))
print(countTriplets([1,3,9,9,27,81], 3))