class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle){
        for(int i=triangle.size()-2;i>=0;i--){
            for(int j=0;j<triangle[i].size();j++){
                int minLeaf = min(triangle[i+1][j], triangle[i+1][j+1]);
                triangle[i][j] += minLeaf;
            }
        }
        return triangle[0][0];
    }
};
