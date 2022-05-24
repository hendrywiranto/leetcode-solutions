# Link to problem
https://leetcode.com/problems/longest-valid-parentheses/

# Link to submitted discussion
https://leetcode.com/problems/longest-valid-parentheses/discuss/2070318/c-on-using-stack-simple-solution

# Time Complexity
Time complexity: `O(n)`
Iterate through array once to flag the valid parentheses index, then iterate it once more to calculate the longest continuous flag

# Memory Complexity
Memory complexity: `O(n)`
Because I use 1D vector to store the flag, the vector size is equal as n
