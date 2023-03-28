class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> cache(grid.size(), vector<int>(grid[0].size(), -1));

        return traverse(grid, cache, 0, 0);
    }

private:
    int traverse(vector<vector<int>> &grid, vector<vector<int>> &cache, int x, int y){
        if(x < 0 || x >= grid[0].size() || y < 0 || y >= grid.size()) return INT_MAX;
        if(cache[y][x] != -1) return cache[y][x];

        int bottom = traverse(grid, cache, x, y+1);
        int right = traverse(grid, cache, x+1, y);
        int minimum = min(bottom, right);
        int pathSum = minimum == INT_MAX ? 0 : minimum;

        cache[y][x] = grid[y][x] + pathSum;

        return cache[y][x];
    }
};
