class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n-2, vector<int>(n-2,0));

        for(int i=1;i<n-1;i++){
            for(int j=1;j<n-1;j++){
                int maxLocal = 0;
                maxLocal = max(maxLocal, grid[i][j]);
                maxLocal = max(maxLocal, grid[i-1][j]);
                maxLocal = max(maxLocal, grid[i-1][j-1]);
                maxLocal = max(maxLocal, grid[i][j-1]);
                maxLocal = max(maxLocal, grid[i+1][j-1]);
                maxLocal = max(maxLocal, grid[i+1][j]);
                maxLocal = max(maxLocal, grid[i+1][j+1]);
                maxLocal = max(maxLocal, grid[i][j+1]);
                maxLocal = max(maxLocal, grid[i-1][j+1]);

                ans[i-1][j-1] = maxLocal;
            }
        }

        return ans;
    }
};
