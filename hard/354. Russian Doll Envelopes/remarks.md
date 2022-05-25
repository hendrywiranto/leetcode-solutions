# Link to problem
https://leetcode.com/problems/russian-doll-envelopes/

# Link to submitted discussion
https://leetcode.com/problems/russian-doll-envelopes/discuss/2073452/CPP-or-Longest-Increasing-Subsequence-solution

# Time Complexity
I iterate the list of envelopes once, so `N`
then for looking the lower_bound in the list of tail of active subsequences is `log N`
So complexity will be `O(N Log N)`

# Memory Complexity
Memory complexity will be `O(N)` as we dont use any extra space for storing the envelopes, just the biggest number of each subsequences
