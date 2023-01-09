class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [ ]( const auto& lhs, const auto& rhs )
        {
           return lhs[0] < rhs[0];
        });

        vector<vector<int>> result = { intervals[0] };
        for(int i=0;i<intervals.size();i++){
            if(result.back()[1] >= intervals[i][0]) result.back()[1] = max(intervals[i][1], result.back()[1]);
            else result.push_back(intervals[i]);
        }

        return result;
    }
};
