
# Time Complexity
This is a 0-1 knapsack DP, I solved it with making a table of memo for each combination of no. of strings used x size of `m` x size of `n`
Because we first iterate through the array, then iterate from 0 `0` to m `0` then for each of that we iterate again from 0 `1` to n `1`, the time complexity should be `O(strings.size() * m * n)`

# Memory Complexity
Same as the time, we make 3D array of `memo[strings.size()][m+1][n+1]`so the memory complexity is also `O(strings.size() * m * n)`
