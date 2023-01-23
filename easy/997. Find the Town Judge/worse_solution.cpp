class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> matrix(n+1, vector<int>(n+1, 0));
        for(auto tr:trust){
            matrix[tr[0]][tr[1]] = 1;
        }

        for(int i=1;i<=n;i++){
            bool candidate = true;
            for(int j=1;j<=n;j++){
                if(j == i) continue;
                if(matrix[j][i] == 0){
                    candidate = false;
                    break;
                }
            }
            if(candidate){
                bool found = true;
                for(int j=1;j<=n;j++){
                    if(matrix[i][j] == 1){
                        found = false;
                        break;
                    }
                }
                if(found) return i;
            }
        }
        return -1;
    }
};
