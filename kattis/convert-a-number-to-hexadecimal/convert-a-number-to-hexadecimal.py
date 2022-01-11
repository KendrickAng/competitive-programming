class Solution:
    def toHex(self, num: int) -> str:
        if num == 0:
            return "0"
        
        numToHex = dict([(i, str(i)) for i in range(10)])
        numToHex[10] = "a"
        numToHex[11] = "b"
        numToHex[12] = "c"
        numToHex[13] = "d"
        numToHex[14] = "e"
        numToHex[15] = "f"
        
        def extract_four(num):
            count = 0
            for power in range(4):
                digit = num & 1
                num >>= 1
                count += digit * pow(2, power)
            return num, numToHex[count]
          
        def twos_complement(num):
            return int(str(bin((1 << 32) - abs(num)))[2:], 2)
            
        ans= []
        if num < 0:
            tc = twos_complement(num)
            while tc != 0:
                tc, hexStr = extract_four(tc)
                ans.append(hexStr)
        else:
            while num > 0:
                num, hexStr = extract_four(num)
                ans.append(hexStr)     
            
        return "".join(reversed(ans))

    
"""
26
1a = 10 * 1 + (1 * 16) = 26

-1

1. convert number to twos completement in binary
2. convert groups of 8 bits into hex form
3. return

1. convert number to ones complement by bitwise not
2. add one
3. convert to hex
"""