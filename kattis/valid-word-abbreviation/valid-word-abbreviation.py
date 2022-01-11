from string import digits

class Solution:
    def validWordAbbreviation(self, word: str, abbr: str) -> bool:
        
        wordPtr = 0
        abbrPtr = 0
        while True:
            # case of ptr exceeding words
            if abbrPtr >= len(abbr) or wordPtr >= len(word):
                return True if (abbrPtr == len(abbr) and wordPtr == len(word)) else False
            #print(abbrPtr, wordPtr)
            
            # check if abbr in digits
            if abbr[abbrPtr] in digits:
                if abbr[abbrPtr] == "0":
                    return False # leading zero
                # consume number
                nums = []
                while abbrPtr < len(abbr) and abbr[abbrPtr] in digits:
                    nums.append(abbr[abbrPtr])
                    abbrPtr += 1
                    
                # move wordPtr
                n = int("".join(nums))
                wordPtr += n
            
            # abbr in letters
            else:
                if word[wordPtr] != abbr[abbrPtr]:
                    return False
         
                abbrPtr += 1
                wordPtr += 1
            
"""
apple a2e false
apple a11le false
apple a02e false
apple a0pple false
apple a1pl false 

apple a3e true
apple 5 true
apple apple true
apple 2p2 true 
apple

start ptr to word
start tpr to abbr

while ptrs are within word bounds:
    if abbr points to number:
        if its leading zero:
            return false
        consume the number, advance ptr to abbr
        advance point to word
        2 cases - abbr points to a letter, or end of word
        if both pointers exceed tghe word:
            if both pointers point to just after both words:
                return True
            else
                return False
    
    if both pointers point to letters
    and theyre not equal:
        return False
    
    advance word pointer
    advance abbr pointer

return True
    
"""