class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int now = 0;
        int p = 0;
        for(int a=1;a<=1000 && now < arr.size();a++){
            if(a == arr[now]){
                now++;
            }
            else {
                p++;
            }

            if(p == k) return a;
        }

        return arr.size() + k;
    }
};
