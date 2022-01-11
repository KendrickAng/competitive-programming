class Solution:
    def addOperators(self, num: 'str', target: 'int') -> 'List[str]':

        N = len(num)
        answers = []
        def recurse(index, prev_operand, current_operand, value, string):

            # Done processing all the digits in num
            if index == N:

                # If the final value == target expected AND
                # no operand is left unprocessed
                if value == target and current_operand == 0:
                    answers.append("".join(string[1:]))
                return

            # Extending the current operand by one digit
            current_operand = current_operand*10 + int(num[index])
            str_op = str(current_operand)

            # To avoid cases where we have 1 + 05 or 1 * 05 since 05 won't be a
            # valid operand. Hence this check
            if current_operand > 0:

                # NO OP recursion
                recurse(index + 1, prev_operand, current_operand, value, string)

            # ADDITION
            string.append('+'); string.append(str_op)
            recurse(index + 1, current_operand, 0, value + current_operand, string)
            string.pop();string.pop()

            # Can subtract or multiply only if there are some previous operands
            if string:

                # SUBTRACTION
                string.append('-'); string.append(str_op)
                recurse(index + 1, -current_operand, 0, value - current_operand, string)
                string.pop();string.pop()

                # MULTIPLICATION
                string.append('*'); string.append(str_op)
                recurse(index + 1, current_operand * prev_operand, 0, value - prev_operand + (current_operand * prev_operand), string)
                string.pop();string.pop()
        recurse(0, 0, 0, 0, [])    
        return answers
"""
1 2 3
1*2*3
1+2+3

2 3 2
2*3+2
2+3*2

1 0 5
1*0+5
10-5

00
0*0
0+0
0-0

generate all possible strings with operators
filter out invalid strings
evaluate each string one by one

strings = [] # store all strings to evaluator
n = len(num)

def dfs(idx, sofar):
    nonlocal strings
    if idx == n:
        string = "".join(sofar)
        if string and string[0].isdigit() and noLeadZeros(string):
            strings.append(string)
        return
    
    # add an operator
    if idx != 0:
        for op in ("+", "-", "*"):
            sofar.append(op)
            sofar.append(num[idx])
            dfs(idx+1, sofar)
            sofar.pop()
            sofar.pop()
    
    # dont add an operator
    sofar.append(num[idx])
    dfs(idx+1, sofar)
    sofar.pop()
    
dfs(0, [])
ans = [s for s in strings if eval(s) == target]
return ans
"""