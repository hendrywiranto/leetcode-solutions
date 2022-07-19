class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;

        for(int i=0;i<numRows;i++){
            if(i == 0) result.push_back({1});
            else if(i == 1) result.push_back({1,1});
            else {
                vector<int> temp;
                for(int j=0;j<=i;j++){
                    if(j == 0) temp.push_back(1);
                    else if(j == i) temp.push_back(1);
                    else {
                        temp.push_back(result[i-1][j-1] + result[i-1][j]);
                    }
                }
                result.push_back(temp);
            }
        }

        return result;
    }
};
