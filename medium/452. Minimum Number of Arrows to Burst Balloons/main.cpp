class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        vector<vector<int>> results = { points[0] };

        for(int i=1;i<points.size();i++){
            vector<int> bacc = results.back();
            bool overlap = false;
            if(points[i][0] >= bacc[0] && points[i][0] <= bacc[1]){
                results.pop_back();
                results.push_back({points[i][0], bacc[1]});
                overlap = true;
            }
            if(points[i][1] >= bacc[0] && points[i][1] <= bacc[1]){
                results.pop_back();
                results.push_back({bacc[0], points[i][1]});
                overlap = true;
            }
            if(!overlap) results.push_back(points[i]);
        }
        for(auto result:results){
            cout << result[0] << " " << result[1] << endl;
        }

        return results.size();
    }
};
