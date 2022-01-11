class Solution {
public:
    bool isOk(string &s, vector<int> &chars, int k) {
        int uniqLetters = 0;
        for (int i: chars) if (i > 0) uniqLetters++;
        if (uniqLetters > (k+1)) return false;
        
        int maxE = *max_element(chars.begin(), chars.end());
        int cnt = 0;
        for (int i: chars) cnt+=i;
        return (cnt-maxE) <= k;
    }
    
    void print(vector<int> &chars) {
        for (auto a: chars) cout << a << " ";
        cout << endl;
    }
    
    int characterReplacement(string s, int k) {
        int l = 0;
        int r = 0;
        int ans = 0;
        int n = s.size();
        vector<int> chars(128, 0);
        while (r < n) {
            char c = s[r];
            chars[c]++;
            
            while (!isOk(s, chars, k)) {
                char cc = s[l];
                chars[cc]--;
                l++;
            }
            
            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};