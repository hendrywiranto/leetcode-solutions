class Solution {
public:
    bool isUgly(int n) {
        if(n <= 0) return false;

        n = div(n, 2);
        n = div(n, 3);
        n = div(n, 5);

        return n == 1;
    }

    int div(int n, int divisor){
        while(n % divisor == 0) n /= divisor;
        return n;
    }
};
// MATH PROBLEM
