class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        map<int,int> memo;
        for(int i=0;i<nums.size();i++){
            memo[nums[i] * -1]++;
        }

        int result = 0;
        int lastCount = 0;
        for(auto m:memo){
            if(m.first == memo.begin()->first){
                lastCount = m.second;
            }
            else {
                result += lastCount;
                lastCount += m.second;
            }
        }

        return result;
    }
};
