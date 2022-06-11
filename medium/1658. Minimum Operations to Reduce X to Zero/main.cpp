class Solution {
public:
    int minOperations(vector<int>& nums, int x){
        map<int,int> prefixSumMap;
        int sumLeft = 0;
        int minCount = INT_MAX;

        prefixSumMap[0] = 0;

        for(int i=0;i<nums.size();i++){
            sumLeft += nums[i];
            prefixSumMap[sumLeft] = i;
            if(x - sumLeft == 0){
                minCount = min<int>(minCount, i + 1);
            }
        }

        if(sumLeft < x) return -1;

        int sumRight = 0;
        for(int i=nums.size()-1;i>=0;i--){
            sumRight += nums[i];
            if(x - sumRight == 0){
                minCount = min<int>(minCount, nums.size() - i);
            }
            else if(prefixSumMap.find(x - sumRight) != prefixSumMap.end() ){
                minCount = min<int>(minCount, prefixSumMap[x - sumRight] + 1 + nums.size() - i);
            }
        }

        return minCount == INT_MAX ? -1 : minCount;
    }
};
