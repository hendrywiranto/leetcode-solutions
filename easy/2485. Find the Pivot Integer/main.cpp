class Solution {
public:
    int pivotInteger(int n) {
        vector<int> prefix(n+1, 0);
        vector<int> suffix(n+1, 0);

        for(int i=1;i<=n;i++){
            if(i==1){
                prefix[i] = i;
                suffix[n+1-i] = n+1-i;
            } else {
                prefix[i] = prefix[i-1] + i;
                suffix[n+1-i] = suffix[n+2-i] + n+1-i;
            }
        }

        for(int i=1;i<=n;i++){
            if(suffix[i] == prefix[i]) return i;
        }

        return -1;    
    }
};
