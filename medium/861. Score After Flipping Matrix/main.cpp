class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {        
        for(int i=0;i<grid.size();i++){
            if(grid[i][0] == 0){
                for(int j=0;j<grid[i].size();j++){
                    if(grid[i][j] == 0) grid[i][j] = 1;
                    else grid[i][j] = 0;
                }
            }
        }

        for(int j=0;j<grid[0].size();j++){
            int zeros = 0, ones = 0;
            for(int i=0;i<grid.size();i++){
                if(grid[i][j] == 0) zeros++;
                else ones++;
            }
            
            if(zeros > ones){
                for(int i=0;i<grid.size();i++){
                    if(grid[i][j] == 0) grid[i][j] = 1;
                    else grid[i][j] = 0;
                }
            }
        }

        int ans = 0;
        for(int i=0;i<grid.size();i++){
            string binStr = "";
            for(int j=0;j<grid[i].size();j++){
                binStr += to_string(grid[i][j]);
            }
            ans += stoi(binStr, nullptr, 2);
        }

        return ans;
    }
};
