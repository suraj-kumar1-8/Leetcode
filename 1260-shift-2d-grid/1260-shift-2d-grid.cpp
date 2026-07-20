class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {

        int n = grid.size();      // rows
        int m = grid[0].size();   // columns

        vector<vector<int>> ans(n, vector<int>(m));

        int total = n * m;
        k %= total;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                int index = i * m + j;

                int newIndex = (index + k) % total;

                int newRow = newIndex / m;
                int newCol = newIndex % m;

                ans[newRow][newCol] = grid[i][j];
            }
        }

        return ans;
    }
};