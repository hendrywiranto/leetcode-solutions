class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int result = 0;
        for(int y=0;y<grid.size();y++){
            for(int x=0;x<grid[0].size();x++){
                if(grid[y][x] == 1){
                    int tmp = traverse(grid, x, y);
                    if(tmp != -1) result += tmp;
                }
            }
        }

        return result;
    }

    int traverse(vector<vector<int>>& grid, int x, int y){
        if(x < 0 || x >= grid[0].size() || y < 0 || y >= grid.size()) return -1;
        if(grid[y][x] == 0) return 0;

        grid[y][x] = 0;

        int left = traverse(grid, x-1, y);
        int bottom = traverse(grid, x, y+1);
        int right = traverse(grid, x+1, y);
        int top = traverse(grid, x, y-1);
        int sum = 0;

        if(left == -1) return -1;
        else sum += left;

        if(bottom == -1) return -1;
        else sum += bottom;

        if(right == -1) return -1;
        else sum += right;

        if(top == -1) return -1;
        else sum += top;

        return sum + 1;
    }
};
