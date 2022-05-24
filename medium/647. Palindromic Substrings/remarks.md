# Link to problem
https://leetcode.com/problems/palindromic-substrings/

# Link to submitted discussion
https://leetcode.com/problems/palindromic-substrings/discuss/2067426/C%2B%2B-or-DP-or-Recursive

# Time Complexity
For time complexity because I iterate the size of strings to 2, then for each size I iterate again for each index possible, it should be `N*N` then for each checkPalindrome there will be `N` times the method actually have to manually determine palindrome of string, if the string appears again, it be taken from the memo
So `O(N*N + N)` = `O(N^2)`

# Memory Complexity
For memory complexity because I use 2D array for memo with the size of `N * N` it will be the memory complexity
So `O(N^2)`
