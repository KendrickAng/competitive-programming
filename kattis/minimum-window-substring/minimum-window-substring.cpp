class Solution {
public:
    string minWindow(string s, string t) {
        // histogram to keep track of critical letters
        // all values will be <= 0 when we have found all critical letters in a window
        // any value is > 0 when we are missing one or more critical characters
        vector<int> chars(128, 0);
        for (char c: t) chars[c]++;
        
        // variables needed for sliding window
        int left = 0; 
        int right = 0;
        int n = s.size();
        int counter = t.size();
        
        // variables to store answer
        int minStart = 0;
        int minLen = INT_MAX;
        
        while (right < n) {
            char c = s[right];
            if (chars[c] > 0) counter--;
            chars[c]--; // register the character as seen in the window
            right++;

            while (counter == 0) {
                char cc = s[left];
                // for min substring, answer updates in inner while loop
                // for max substring, answer updates after the inner while loop, in outer loop
                if (right - left < minLen) { 
                    minStart = left;
                    minLen = right - left;
                }
                chars[cc]++; // register the character as removed from window
                
                // if we are now missing a char in out window, increase the counter
                if (chars[cc] > 0) counter++;
                left++;
            }
            
        }
        
        if (minLen != INT_MAX) return s.substr(minStart, minLen);
        return "";
    }
};