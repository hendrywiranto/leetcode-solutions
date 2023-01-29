class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int front, back;
        vector<vector<int>> ans;

        for(int i=0;i<nums.size();i++){
            front = i+1;
            back = nums.size()-1;
            while(front < back){
                int tmp = nums[front] + nums[back];

                if(tmp < nums[i]*-1) front++;
                else if(tmp > nums[i]*-1) back--;
                else {
                    vector<int> comb = {nums[i], nums[front], nums[back]};
                    ans.push_back(comb);

                    while(front < back && nums[front] == comb[1]) front++;
                    while(front < back && nums[back] == comb[2]) back--;
                }
            }
            while(i+1 < nums.size()-1 && nums[i] == nums[i+1]) i++;
        }

        return ans;
    }
};

// -4 -1 -1 0 1 2
