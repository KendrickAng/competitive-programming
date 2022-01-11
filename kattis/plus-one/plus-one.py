class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        digits = digits[::-1]
        carry = 1
        for i in range(len(digits)):
            digits[i] += carry
            carry = 0
            
            if digits[i] >= 10:
                carry = digits[i] // 10
                digits[i] %= 10
                
        if carry != 0:
            digits.append(carry)
            
        return digits[::-1]
            