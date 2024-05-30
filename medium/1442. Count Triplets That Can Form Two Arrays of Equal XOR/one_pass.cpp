class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int ans = 0;

        for(int i=0;i<arr.size();i++){
            for(int k=i+1;k<arr.size();k++){
                int total = 0;
                for(int itr=i;itr<=k;itr++){
                    total ^= arr[itr];
                }
                if(total == 0) ans += k - i;
            }
        }      

        return ans;
    }
};
