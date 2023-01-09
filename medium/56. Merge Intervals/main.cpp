class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result = { intervals[0] };
        for(int i=1;i<intervals.size();i++){
            vector<int> b = result.back();
            if(intervals[i][0] <= b[1]){
                result.back()[1] = max(b[1], intervals[i][1]);
            }
            else {
                result.push_back(intervals[i]);
            }
        }

        return result;
    }
};
