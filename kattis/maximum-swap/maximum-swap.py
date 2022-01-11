class Solution:
    
    def maximumSwap(self, num: int) -> int:
        def swap(digits, i, j):
            tmp = digits[i]
            digits[i] = digits[j]
            digits[j] = tmp
            
        digits = list(str(num))
        lastSeenIdx = [-1] * 10
        # generate buckets
        for i, digit in enumerate(digits):
            lastSeenIdx[int(digit)] = i

            # one pass from left to right
        for i, digit in enumerate(digits):
            for j in range(9, -1, -1):
                lastIdx = lastSeenIdx[j]
                # if last indx is greater than current, swap
                if int(digit) < j and lastIdx > i:
                    swap(digits, i, lastIdx)
                    return int("".join(digits))
        return num