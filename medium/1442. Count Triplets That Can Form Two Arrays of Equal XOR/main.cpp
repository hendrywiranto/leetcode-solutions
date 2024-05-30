class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int a = 0;
        int b = 0;
        int ans = 0;

        for(int i=0;i<arr.size();i++){
            for(int k=i+1;k<arr.size();k++){
                a = 0; b = 0;
                int j=i+1;
                for(int itr=i;itr<j;itr++){
                    a ^= arr[itr];
                }
                for(int itr=j;itr<=k;itr++){
                    b ^= arr[itr];
                }
                for(;j<=k;j++){
                    if(a == b) ans++;
                    a ^= arr[j];
                    b ^= arr[j];
                }
            }
        }      

        return ans;
    }
};
