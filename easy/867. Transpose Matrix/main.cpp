class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> result;

        for(int i=0;i<matrix[0].size();i++){
            result.push_back({});

            for(int j=0;j<matrix.size();j++){
                result[i].push_back(matrix[j][i]);
            }
        }

        return result;
    }
};
