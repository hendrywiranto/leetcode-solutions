class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<pair<float,pair<int,int>>> ans;

        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                ans.push_back(make_pair(arr[i] * 1.0 /arr[j], make_pair(arr[i], arr[j])));            
            }
        }

        sort(ans.begin(), ans.end());

        return {ans[k-1].second.first, ans[k-1].second.second};
    }
};
