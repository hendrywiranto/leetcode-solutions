class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int deletedCol = 0;
        for(int col=0;col<strs[0].size();col++){
            char prev = strs[0][col];
            for(int i=0;i<strs.size();i++){
                if(strs[i][col] < prev){
                    deletedCol++;
                    break;
                }
                prev = strs[i][col];
            }
        }

        return deletedCol;
    }
};
