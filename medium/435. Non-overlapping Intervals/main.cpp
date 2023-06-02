bool comp(vector<int> &a,vector<int> &b) {
	return a[1]<b[1];
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        vector<int> back = intervals[0];
        int result = 0;

        for(int i=1;i<intervals.size();i++){
            if(back[1] > intervals[i][0]){
                result++;
            }
            else {
                back = intervals[i];
            }
        }

        return result;
    }
};
