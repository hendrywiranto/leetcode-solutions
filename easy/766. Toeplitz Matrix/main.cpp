class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        vector<int> temp = matrix[0];

        for(int i=1;i<matrix.size();i++){
            for(int j=1;j<matrix[0].size();j++){
                if(matrix[i][j] != temp[j-1]) return false;
            }

            temp = matrix[i];
        }

        return true;
    }
};
