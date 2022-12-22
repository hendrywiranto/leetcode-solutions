class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<int> marked(100001, -1);
        vector<vector<int>> result;

        for(int i=0;i<intervals.size();i++){
            for(int j=intervals[i][0];j<=intervals[i][1];j++){
                marked[j] = intervals[i][0];
            }
        }

        int start = newInterval[0];
        int end = newInterval[1];
        for(int i=start;i<=100000;i++){
            if(marked[i] != -1 && marked[i] < start){
                start = marked[i];
            }
            else if(marked[i] >= start && marked[i] <= end && i > end){
                marked[i] = start;
            }
            else if(i > end){
                break;
            }
            else {
                marked[i] = start;
            }
        }

        start = -1;
        for(int i=0;i<=100000;i++){
            if(i == 100000 && start != -1){
                result.push_back({start, i});
            }

            if(start != -1 && marked[i] != start){
                result.push_back({start, i-1});
                start = marked[i];
            }
            else if(start != -1 && marked[i] == start){
                continue;
            }
            else if(marked[i] != -1){
                start = i;
            }
        }

        return result;
    }
};
