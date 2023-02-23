class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = INT_MAX, right = 0, mid = 0;
        int result = INT_MAX;

        for(auto w:weights){
            left = min(left, w);
            right += w;
        }

        while(left <= right){
            mid = left + (right-left)/2;
            if(checkAvailability(weights, mid, days, result)){
                right = mid-1;
            }
            else {
                left = mid+1;
            }
        }

        return result;
    }

    bool checkAvailability(vector<int> weights, int capacity, int days, int &result){
        int i = 1, j = 0;
        while(i <= days){
            int now = 0;

            while(j < weights.size() && now + weights[j] <= capacity){
                now += weights[j];
                j++;
            }
            i++;
        }

        if(j == weights.size()) result = min(result, capacity);
        return j == weights.size();
    }
};
