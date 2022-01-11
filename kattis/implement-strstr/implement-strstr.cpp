class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle == "") return 0;
        if (haystack == "") return -1;
        size_t pos = haystack.find(needle);
        if (pos == string::npos) return -1;
        return pos;
    }
};