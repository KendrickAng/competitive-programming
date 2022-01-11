class Solution {
private:
    int rows, cols;
    
    void flood(vector<vector<char>>& grid, int r, int c) {
        if (r < 0 || r >= rows || c < 0 || c >= cols) return;
        if (grid[r][c] == '0') return;
        
        vector<int> x = {0, 1, 0, -1}; // N E S W
        vector<int> y = {-1, 0, 1, 0};
        grid[r][c] = '0';
        for (int i = 0; i < 4; i++) {
            flood(grid, r + y[i], c + x[i]);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        int ans = 0;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == '1') {
                    ans++;
                    flood(grid, r, c);
                }
            }
        }
        return ans;
    }
};