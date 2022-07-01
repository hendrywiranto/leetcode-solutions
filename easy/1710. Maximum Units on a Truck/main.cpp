class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] > b[1];
        });

        int result = 0, countNow = 0;
        for(int i=0;i<boxTypes.size();i++){
            int take = boxTypes[i][0] > truckSize - countNow ? truckSize - countNow : boxTypes[i][0];

            countNow += take;
            result += take * boxTypes[i][1];
        }

        return result;
    }
};
