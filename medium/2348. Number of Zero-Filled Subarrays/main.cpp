class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long result = 0;

        int subSize = 0;
        for(int i=0;i<=nums.size();i++){
            if(i == nums.size() || nums[i] != 0){
                result += sumLessThan(subSize);
                subSize = 0;
            }
            else subSize++;
        }

        return result;
    }

    long long sumLessThan(long long n){
        return (n-1) * n / 2 + n;
    }
};
