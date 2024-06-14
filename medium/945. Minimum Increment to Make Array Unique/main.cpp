class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        if(nums.size() <= 1) return 0;
        
        vector<int> numCtr(100001, 0);
        for(int i=0;i<nums.size();i++){
            numCtr[nums[i]]++;
        }

        int ans = 0;
        for(int i=0;i<100001;i++){
            if(numCtr[i] <= 1) continue;
            if(i == 100000 && numCtr[i] > 1){
                int remain = numCtr[i]-1;
                while(remain > 0){
                    ans += remain;
                    remain--;
                }
            }
            else {
                ans += numCtr[i]-1;
                numCtr[i+1] += numCtr[i]-1;
                numCtr[i] = 1;                
            }
        }

        return ans;
    }
};
