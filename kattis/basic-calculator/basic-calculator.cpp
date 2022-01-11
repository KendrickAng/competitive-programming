using namespace std;

class Solution {
public:
    int i = 0;
    
    int calculate(string s) {
        int operand = 0;
        int result = 0;
        int nextOperandSign = 1;
        
        while (i < s.size()) {
            char c = s[i++];
            
            if (c == ' ') {
                continue;
            }
            else if (isdigit(c)) {
                operand = (operand*10) + (c-'0');
            }
            else if (c == '(') {
                operand = calculate(s);
            }
            else if (c == ')') {
                break;
            }
            else {
                result += nextOperandSign * operand;
                nextOperandSign = (c == '+') ? 1 : -1;
                operand = 0;
            }
        }
        
        return result + (nextOperandSign * operand);
    }
};