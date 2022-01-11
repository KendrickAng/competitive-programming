#include <bits/stdc++.h>

class Solution {
public:
    enum {
        UNVISITED = -1,
        VISITED = -2,
        EXPLORED = -3,
    };
    
    vector<vector<int>> al;
    vector<int> dfs_num;
    vector<int> ts;
    vector<int> indegree;
    bool hasCycle = false;
    
    void toposort(int u) {
        dfs_num[u] = VISITED;
        for (auto &v: al[u]) {
            if (dfs_num[v] == UNVISITED) {
                toposort(v);
            }
        }
        ts.push_back(u);
    }
    
    void cycleCheck(int u) {
        if (hasCycle) return;
        dfs_num[u] = EXPLORED;
        for (auto &v: al[u]) {
            if (dfs_num[v]== UNVISITED) {
                cycleCheck(v);
            }
            else if (dfs_num[v] == EXPLORED) {
                hasCycle = true;
            }
            else if (dfs_num[v] == VISITED) {
                // do nothing
            }
        }
        dfs_num[u] = VISITED; // done
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // init vars
        int V = numCourses;
        al.assign(V, vector<int>{});
        indegree.assign(V, 0);
        ts.clear();
        
        // init graph
        for (int i = 0; i < prerequisites.size(); i++) {
            vector<int> prereq = prerequisites[i];
            int u = prereq[1];
            int v = prereq[0];
            indegree[v]++;
            al[u].push_back(v);
        }
        
        // cycle check
        dfs_num.assign(V, UNVISITED);
        for (int u = 0; u < V; u++) {
            if (dfs_num[u] == UNVISITED) {
                cycleCheck(u);
            }
        }
        
        // toposort
        dfs_num.assign(V, UNVISITED);
        for (int u = 0; u < V; u++) {
            if (dfs_num[u] == UNVISITED) {
                toposort(u);
            }
        }
        
        // check ans
        if (hasCycle) {
            return vector<int>();
        }
        reverse(ts.begin(), ts.end());
        return ts;
    }
};