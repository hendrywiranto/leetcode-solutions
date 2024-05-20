class Solution {
private:    
    int ans = 0;
    void buildSubset(vector<int>& nums, int l, int size, int curr, int num){
        if(size == curr){
            ans += num;
            return;
        }

        for(int i=l;i<nums.size();i++){
            num ^= nums[i];
            buildSubset(nums, i+1, size, curr+1, num);
            num ^= nums[i];
        }

        return;
    }
public:
    int subsetXORSum(vector<int>& nums) {        
        for(int i=1;i<=nums.size();i++){
            buildSubset(nums, 0, i, 0, 0);
        }

        return ans;
    }
};
