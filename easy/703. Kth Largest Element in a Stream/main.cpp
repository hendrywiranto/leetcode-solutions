class KthLargest {
private:
    int k;
    priority_queue<int> pq;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int i=0;i<nums.size();i++){
            add(nums[i]);
        }
    }

    int add(int val) {
        pq.push(val * -1);
        if(pq.size() > k) pq.pop();

        return pq.top() * -1;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
