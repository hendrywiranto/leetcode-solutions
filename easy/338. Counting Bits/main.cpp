class Solution {
private:
    int countOnes(vector<int> &memo, int n){
        if(n == 0) return 0;
        if(memo[n] != 0) return memo[n];

        if(n % 2 == 0) memo[n] = countOnes(memo, n / 2);
        else memo[n] = 1 + countOnes(memo, n / 2);

        return memo[n];
    }

public:
    vector<int> countBits(int n) {
        vector<int> memo(n+1, 0);

        for(int i=0;i<=n;i++){
            countOnes(memo, i);
        }

        return memo;
    }
};
