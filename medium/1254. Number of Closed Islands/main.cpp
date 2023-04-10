class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int result = 0;
        for(int y=0;y<grid.size();y++){
            for(int x=0;x<grid[y].size();x++){
                if(grid[y][x] == 0 && traverse(x, y, grid)) result++;
            }
        }

        return result;
    }

private:
    bool traverse(int x, int y, vector<vector<int>>& grid){
        if(x < 0 || x >= grid[0].size() || y < 0 || y >= grid.size()) return true;
        if(grid[y][x] == 1) return true;

        bool curr = true;
        if(grid[y][x] == 0 && (x == 0 || x == grid[0].size()-1 || y == 0 || y == grid.size()-1)) curr = false;

        grid[y][x] = 1;
        bool left = traverse(x-1, y, grid);
        bool bottom = traverse(x, y+1, grid);
        bool right = traverse(x+1, y, grid);
        bool top = traverse(x, y-1, grid);
        return curr && left && bottom && right && top;
    }
};
