class Solution {
private:
    bool isPalindromeStupid(string s) {
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] != s[n-1-i]) return false;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        bool stillOk = true;
        int n = s.size();
        int left = 0;
        int right = n-1;
        while (left <= right) {
            if (s[left] != s[right]) {
                string a = s.substr(left, right-left);
                //cout << a << endl;
                string b = s.substr(left+1, right-left);
                //cout << b << endl;
                return isPalindromeStupid(a) || isPalindromeStupid(b);
            }
            else {
                left++;
                right--;
            }
        }
        return true;
    }
};