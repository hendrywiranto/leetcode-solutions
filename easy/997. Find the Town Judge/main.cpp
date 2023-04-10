class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trustLevel(n, 0);

        for(auto tr:trust){
            trustLevel[tr[1]-1]++;
            trustLevel[tr[0]-1]--;
        }
        for(int i=0;i<trustLevel.size();i++){
            if(trustLevel[i] == n-1) return i+1;
        }

        return -1;
    }
};
