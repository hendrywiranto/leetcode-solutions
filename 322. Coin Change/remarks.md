# Link to problem
https://leetcode.com/problems/coin-change/

# Link to submitted discussion
https://leetcode.com/problems/coin-change/discuss/2067670/C%2B%2B-or-DP

# Time Complexity
Because I iterate from 0 to amount (where amount is k) and for each iteration, I iterate all the coins denominator available (size n), the complexity for this solution is `O(k * n)`

# Memory Complexity
Memory complexity is `O(10^4)` because I use the remaining coins as state and the maximum amount of coins is 10^4
