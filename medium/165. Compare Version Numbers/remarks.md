# Link to problem
https://leetcode.com/problems/compare-version-numbers/

# Link to submitted discussion
https://leetcode.com/problems/compare-version-numbers/submissions/1248183956/?envType=daily-question&envId=2024-05-03

# Time Complexity
- m is version1.length, n is version2.length
- x is versions in version1, y is version in version2
- So time complexity will be m + n for the string split
- And for the version comparison will be max(x,y) * complexity of stoi func

# Memory Complexity
`O(x + y)`
