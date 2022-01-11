class Solution {
public:
    string addBinary(string a, string b) {
        if (a == "0" && b == "0") return "0";
        int n = max(a.size(), b.size());
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        if (a.size() < b.size()) swap(a, b);
        int toAdd = a.size() - b.size();
        for (int i = 0; i < toAdd; i++) {
            b += '0';
        }
        
        string ret = "";
        int carry = 0;
        for (int i = 0; i < n; i++) {
            int sum = stoi(string(1,a[i])) + stoi(string(1,b[i])) + carry;
            if (sum == 0) {
                ret += '0';
            }
            else if (sum == 1) {
                carry = 0;
                ret += '1';
            }
            else if (sum == 2) {
                carry = 1;
                ret += '0';
            }
            else {
                carry = 1;
                ret += '1';
            }
        }
        ret += (carry == 0) ? '0' : '1';
        
//         bool hasOne = false;
//         for (char c: ret) if (c == '1') hasOne = true;
        
        string ans = "";
        bool seenOne = false;
        for (int i = ret.size()-1; i >= 0; i--) {
            if (ret[i] == '0' && seenOne) {
                ans += ret[i];
            }
            else if (ret[i] == '1') {
                seenOne = true;
                ans += ret[i];
            }
            else {
                // ignore
            }
        }
        return ans;
    }
};