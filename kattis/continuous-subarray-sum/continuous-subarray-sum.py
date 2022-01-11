class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        # running sum -> index of first occurence
        mapping = {}
        mapping[0] = -1
        runSum = 0

        for i, num in enumerate(nums):
            runSum += num
            want = runSum % k
            # print(f"{runSum} have: {runSum % k} want: {want}")
            if want in mapping and (i-mapping[want]) >= 2:
                # print(mapping)
                return True

            key = runSum % k
            if key not in mapping:
                # print(f"add: {key} {i}")
                mapping[key] = i

        # print(mapping)
        return False    
"""
23 2 6 4 7. k = 13
31

0: -1
10: 0
12: 1


23 2 4 6 7, k = 6

23 2 6 4 7, k = 6

# running sum -> index of first occurence
mapping = {}
mapping[0] = -1
runSum = 0

for i, num in enumerate(nums):
    runSum += num
    want = k - (runSum % k)
    if want in mapping and (i-mapping[want]) >= 2:
        return True
    
    mapping[runSum % k] = i
    
return False
"""