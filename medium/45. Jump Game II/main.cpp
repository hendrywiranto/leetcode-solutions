class Solution {
public:
    int jump(vector<int>& nums) {
        int i = 0, result = 0;
        int jump = 1;
        int finish = nums.size()-1;
        int farthest = 0, farthestIndex = 0;

        while(i < finish){
            while(jump <= nums[i]){
                if(i+jump >= finish) return result+1;
                else {
                    if(farthest < i + jump + nums[i+jump]){
                        farthest = i + jump + nums[i+jump];
                        farthestIndex = i + jump;
                    }
                }
                jump++;
            }

            result++;
            i = farthestIndex;
            jump = 1;
        }

        return result;
    }
};
