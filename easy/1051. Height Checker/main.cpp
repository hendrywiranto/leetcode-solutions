class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> heightsOri = heights;
        sort(heights.begin(), heights.end());
        int ans = 0;

        for(int i=0;i<heights.size();i++){
            if(heights[i] != heightsOri[i]){
                ans++;
            }
        }

        return ans;
    }
};
