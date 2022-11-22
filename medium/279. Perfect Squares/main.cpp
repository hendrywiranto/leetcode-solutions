class Solution {
private:
    vector<int> memo;
public:
    int numSquares(int n) {
        memo = vector<int>(10001, -1);
        return findCombination(n);
    }

    int findCombination(int n){
        if(n == 1 || n == 0) return n;
        if(n < 0) return 20000;
        if(memo[n] != -1) return memo[n];

        int least = INT_MAX;
        for(int j=1;j*j<=n;j++){
            least = min(least, 1 + findCombination(n-j*j));
        }

        memo[n] = least;
        return least;
    }
};
