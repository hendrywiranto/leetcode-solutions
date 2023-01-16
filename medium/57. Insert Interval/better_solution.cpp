class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        bool newInsert = false;

        for(auto interval:intervals){
            bool merge = false;
            if(interval[0] <= newInterval[0] && interval[1] >= newInterval[0]){
                newInterval[0] = interval[0];
                merge = true;
            }
            if(interval[0] <= newInterval[1] && interval[1] >= newInterval[1]){
                newInterval[1] = interval[1];
                merge = true;
            }

            if(merge) continue;
            else if(!newInsert && interval[0] > newInterval[1]){
                result.push_back(newInterval);
                newInsert = true;
            }
            else if(interval[0] >= newInterval[0] && interval[1] <= newInterval[1]) continue;

            result.push_back(interval);
        }

        if(result.size() == 0) return { newInterval };
        else if(!newInsert){
            result.push_back(newInterval);
            return result;
        }
        else return result;
    }
};
