class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;

        for(int row=0;row<grid.size();row++){
            for(int col=0;col<grid[row].size();col++){
                if(grid[row][col] == '1'){
                    traverseIsland(grid, row, col);
                    result++;
                }
            }
        }

        return result;
    }

private:
    void traverseIsland(vector<vector<char>>& grid, int x, int y){
        if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()) return;
        if(grid[x][y] == '0') return;

        grid[x][y] = '0';

        traverseIsland(grid, x, y-1);
        traverseIsland(grid, x+1, y);
        traverseIsland(grid, x, y+1);
        traverseIsland(grid, x-1, y);
    }
};
