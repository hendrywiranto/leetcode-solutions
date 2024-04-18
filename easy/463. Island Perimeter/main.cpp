class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int total = 0;

        for(int row=0;row<grid.size();row++){
            for(int col=0;col<grid[row].size();col++){
                if(grid[row][col] == 0) continue;

                if(row == 0) total++;
                if(col == 0) total++;
                if(row == grid.size()-1) total++;
                if(col == grid[row].size()-1) total++;

                if(row+1 < grid.size() && grid[row+1][col] == 0) total++;
                if(col+1 < grid[row].size() && grid[row][col+1] == 0) total++;
                if(row-1 >= 0 && grid[row-1][col] == 0) total++;
                if(col-1 >= 0 && grid[row][col-1] == 0) total++;
            }
        }

        return total;
    }
};
