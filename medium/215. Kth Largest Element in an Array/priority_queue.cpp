class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;

        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }

        int i=1;
        while(!pq.empty() && i<k){
            pq.pop();
            i++;
        }

        return pq.top();
    }
};
