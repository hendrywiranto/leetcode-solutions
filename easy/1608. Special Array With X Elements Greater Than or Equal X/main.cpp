class Solution {
private:
    int check(vector<int>& nums, int candidate){
        int ctr = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] >= candidate) ctr++;
        }

        return ctr;
    }
public:
    int specialArray(vector<int>& nums) {
        int l=0,r=nums.size();
        int mid = 0;
        int ans = -1;

        while(l <= r){
            mid = l + (r-l) / 2;
            int matched = check(nums, mid);
            if(matched > mid){
                l = mid+1;
            }
            else if(matched < mid){
                r = mid-1;
            }
            else {                
                ans = mid;
                break;
            }
        }

        return ans;
    }
};
