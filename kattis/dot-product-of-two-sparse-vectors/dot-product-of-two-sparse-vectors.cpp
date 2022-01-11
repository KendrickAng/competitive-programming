class SparseVector {
private:
    vector<int> myvec;
public:
    
    SparseVector(vector<int> &nums) {
        myvec = nums;
    }
    
    int& operator[](int idx) {
        return myvec[idx];
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int n = myvec.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += myvec[i] * vec[i];
        }
        return ans;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);