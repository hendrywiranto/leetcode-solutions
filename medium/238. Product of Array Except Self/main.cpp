class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> fromBegin(n, 1);
        vector<int> fromLast(n,1);

        for(int i=0;i<nums.size();i++){
            fromBegin[i] *= nums[i];
            fromLast[n-i-1] *= nums[n-i-1];

            if(i != 0){
                fromBegin[i] *= fromBegin[i-1];
                fromLast[n-i-1] *= fromLast[n-i];
            }
        }

        vector<int> result;
        for(int i=0;i<n;i++){
            int temp = 1;
            if(i != 0) temp *= fromBegin[i-1];
            if(i != n-1) temp *= fromLast[i+1];
            result.push_back(temp);
        }

        return result;
    }
};
