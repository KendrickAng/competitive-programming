#include <bits/stdc++.h>

using namespace std;

class RandomizedSet {
public:
    vector<int> arr;
    unordered_map<int,int> valToIdx;
    default_random_engine generator;
    
    /** Initialize your data structure here. */
    RandomizedSet() {
        arr = vector<int>();
        valToIdx = unordered_map<int,int>{};
    }
    
    bool containsE(int val) {
        return valToIdx.find(val) != valToIdx.end();
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (containsE(val)) {
            return false;
        }
        valToIdx[val] = arr.size(); // index in array is n
        arr.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (containsE(val)) {
            int i = valToIdx[val];
            int j = arr.size()-1;
            int valJ = arr[j];
            arr[i] = valJ;
            arr.pop_back();
            valToIdx[valJ] = i;
            valToIdx.erase(val);
            return true;
        }
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        uniform_int_distribution<int> distribution(0, arr.size()-1);
        int idx = distribution(generator);
        return arr[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */