using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        bool carry = false;
        string ret = "";
        int i;
        for (i = 0; i < min(num1.size(), num2.size()); i++) {
            int a = num1[i] - '0';
            int b = num2[i] - '0';
            int ab = a + b + carry;
            carry = false;
            if (ab >= 10) {
                carry = true;
                ab -= 10;
            }
            ret += to_string(ab);
        }
        
        if (num1.size() > num2.size()) swap(num1, num2);
        for (; i < num2.size(); i++) {
            int a = num2[i] - '0';
            int ab = a + carry;
            carry = false;
            if (ab >= 10) {
                carry = true;
                ab -= 10;
            }
            ret += to_string(ab);
        }
        if (carry) ret += "1";
        
        reverse(ret.begin(), ret.end());
        return ret;
    }
};