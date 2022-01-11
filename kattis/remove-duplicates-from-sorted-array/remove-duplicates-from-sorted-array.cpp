class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int currMem = -1000;
        int ret = 0;
        int p1 = 0;
        int p2 = 0;
        
        while (p2 < nums.size()) {
            int curr = nums[p2];
            if (curr != currMem) {
                nums[p1++] = curr;
                currMem = curr;
                ret++;
                while (nums[p2] == curr) {
                    p2++;
                    if (p2 >= nums.size()) break;
                }
            }
        }
        
        return ret;
    }
};