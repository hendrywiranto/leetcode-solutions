class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = pow(2, nums.size());
        vector<int> mem(n, 0);

        for(int i=0;i<nums.size();i++){
            mem[stoi(nums[i], 0, 2)] = 1;
        }
        for(int i=0;i<n;i++){
            if(mem[i] == 0) return bitset<16>(i).to_string().substr(16-nums.size(), nums.size());
        }

        return "";
    }
};
