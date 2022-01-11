#include <bits/stdc++.h>

class Solution {
public:
    int area = 0;
    
    void flood(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size()) return;
        if (grid[r][c] == 0) return;
        int rOff[] = {-1, 0, 1, 0};
        int cOff[] = {0, 1, 0, -1};
        grid[r][c] = 0;
        area++;
        for (int i = 0; i < 4; i++) {
            flood(grid, r+rOff[i], c+cOff[i]);
        }
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    area = 0;
                    flood(grid, i, j);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};