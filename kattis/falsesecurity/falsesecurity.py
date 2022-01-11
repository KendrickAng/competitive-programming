import sys

code = {
    "A": ".-",
    "B": "-...",
    "C": "-.-.",
    "D": "-..",
    "E": ".",
    "F": "..-.",
    "G": "--.",
    "H": "....",
    "I": "..",
    "J": ".---",
    "K": "-.-",
    "L": ".-..",
    "M": "--",
    "N": "-.",
    "O": "---",
    "P": ".--.",
    "Q": "--.-",
    "R": ".-.",
    "S": "...",
    "T": "-",
    "U": "..-",
    "V": "...-",
    "W": ".--",
    "X": "-..-",
    "Y": "-.--",
    "Z": "--..",
    "_": "..--",
    ",": ".-.-",
    ".": "---.",
    "?": "----",    
}
code_rev = {v: k for k, v in code.items()}
line = sys.stdin.readline()
while line != "":
    line = line[:-1] # remove the "\n"
    morse_str = ""
    morse_num = ""
    for c in line:
        morse_str += code[c]
        morse_num += str(len(code[c]))
    morse_num_rev = morse_num[::-1]
    ans = ""
    i = 0
    for num in morse_num_rev:
        num = int(num)
        ans += code_rev[morse_str[i:i+num]]
        i += num
    print(ans)

    line = sys.stdin.readline()