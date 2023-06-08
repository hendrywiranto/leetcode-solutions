class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int result = 0;
        int m = grid.size();
        int n = grid[0].size();
        int i = m-1;
        int j = 0;

        while(i >= 0 && j < n){
            if(grid[i][j] < 0){
                if(i == 0){
                    result += m;
                    j++;
                }
                else i--;
            }
            else {
                result += m - (i+1);
                j++;
            }
        }

        return result;
    }
};
