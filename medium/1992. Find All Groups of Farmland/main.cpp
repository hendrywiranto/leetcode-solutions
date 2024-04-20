class Solution {
private:
    vector<int> findCoordinates(vector<vector<int>>& land, int row, int col){
        int r1 = row, c1 = col, r2, c2;

        while(row+1 < land.size() && land[row+1][col] == 1){
            row++;
        }
        r2 = row;
            
        while(col+1 < land[row].size() && land[row][col+1] == 1){
            col++;
        }
        c2 = col;

        for(int i=r1;i<=r2;i++){
            for(int j=c1;j<=c2;j++){
                land[i][j] = 0;
            }
        }

        return { r1, c1, r2, c2 };
    }

public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;

        for(int i=0;i<land.size();i++){
            for(int j=0;j<land[i].size();j++){
                if(land[i][j] == 1){                    
                    vector<int> farm = findCoordinates(land, i, j);
                    ans.push_back(farm);
                }
            }
        }

        return ans;
    }
};
