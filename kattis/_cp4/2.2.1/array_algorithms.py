import bisect

arr = [2,5,3,4,1]
arr.sort()
print(arr)
print(f"binary search pos for 4: {bisect.bisect_left(arr, 4)}")
