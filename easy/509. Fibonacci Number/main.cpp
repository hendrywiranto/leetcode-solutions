class Solution {
private:
    int memo[31] = { 0 };
public:
    int fib(int n) {
        if(n == 0 || n == 1) return n;
        if(memo[n] != 0) return memo[n];

        memo[n] = fib(n-1) + fib(n-2);
        return memo[n];
    }
};
