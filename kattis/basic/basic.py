INTEGER_START = 1
INTEGER_END = 2
INTEGER = 3
BASE_INT_START = 4
BASE_INT_END = 5
BASE_INT = 6

state = INTEGER_START
line = ""
line_idx = -1
curr_int = ""
parsed_int = -1

BASE_TO_NUM = {'0': 0, '1': 1, '2': 2, '3': 3, '4': 4, '5': 5, '6': 6, '7': 7, '8': 8, '9': 9, 'a': 10, 'b': 11, 'c': 12, 'd': 13, 'e': 14, 'f': 15}
ALLOWED_BASE_CHARS = BASE_TO_NUM.keys()
ALLOWED_BASE_ALPHA = {'a','b','c','d','e'}

def init():
    global state, line_idx, curr_int, parsed_int
    state = INTEGER_START
    line_idx = 0
    curr_int = ""
    parsed_int = -1

def is_numeric_alpha():
    return is_valid_idx() and line[line_idx] in ALLOWED_BASE_CHARS

def is_numeric():
    return is_valid_idx() and line[line_idx].isnumeric()

def is_hash():
    return is_valid_idx() and line[line_idx] == '#'

def is_valid_idx():
    return line_idx >= 0 and line_idx < len(line)

def is_eof():
    return line_idx >= len(line)

def main():
    global line, state, line_idx, is_ok, curr_int, parsed_int
    N = int(input())
    for _ in range(N):
        line = input()
        init()

        while not is_eof():
            c = line[line_idx]

            if state == INTEGER_START:
                if not (c.isnumeric() and int(c) >= 0 and int(c) <= 9): break
                if not (len(curr_int) == 0): break
                state = INTEGER
            elif state == INTEGER:
                if not (int(c) >= 0 and int(c) <= 9): break
                curr_int += c
                line_idx += 1
                if is_eof() or is_hash(): state = INTEGER_END
                elif is_numeric(): state = INTEGER
                else: break
            elif state == INTEGER_END:
                if not curr_int.isnumeric(): break
                parsed_int = int(curr_int)
                curr_int = ""
                if not is_eof() and is_hash(): state = BASE_INT_START
                else: break
            elif state == BASE_INT_START:
                if not is_hash(): break
                if not (parsed_int >= 2 and parsed_int <= 16): break
                line_idx += 1
                state = BASE_INT
            elif state == BASE_INT:
                if not (is_numeric_alpha()): break
                if not (parsed_int > BASE_TO_NUM[c]): break
                curr_int += c
                line_idx += 1
                if is_eof(): break
                elif is_hash(): state = BASE_INT_END
                elif is_numeric_alpha(): state = BASE_INT
                else: break
            elif state == BASE_INT_END:
                try:
                    parsed_int = int(curr_int, parsed_int)
                except:
                    break
                curr_int = ""
                line_idx += 1
                if not is_eof() and is_hash():  state = BASE_INT_START
                else: break
        
        if is_eof() and (state == INTEGER_END or state == BASE_INT_END):
            print("yes")
        else:
            print("no")

if __name__ == "__main__":
    main()