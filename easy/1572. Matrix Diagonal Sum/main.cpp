class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int result = 0;

        for(int i=0;i<mat.size();i++){
            if(mat[i][i] != 0){
                result += mat[i][i];
                mat[i][i] = 0;
            }
            if(mat[mat.size()-i-1][i] != 0){
                result += mat[mat.size()-i-1][i];
                mat[mat.size()-i-1][i] = 0;
            }
        }

        return result;
    }
};
