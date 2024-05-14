class Solution {
private:
    int ans = 0;

    void traverse(vector<vector<int>>& grid, vector<vector<int>>& memo, int row, int col, int total){
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) return;
        if(memo[row][col] == 1) return;
        if(grid[row][col] == 0) return;

        memo[row][col] = 1;
        total += grid[row][col];
        ans = max(ans, total);

        traverse(grid, memo, row, col-1, total);
        traverse(grid, memo, row+1, col, total);
        traverse(grid, memo, row, col+1, total);
        traverse(grid, memo, row-1, col, total);

        memo[row][col] = 0;

        return;
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                vector<vector<int>> memo(grid.size(), vector<int>(grid[0].size(), 0));
                traverse(grid, memo, i, j, 0);
            }
        }        

        return ans;
    }
};
