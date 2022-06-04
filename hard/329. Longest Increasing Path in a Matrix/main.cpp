class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        this->matrix = matrix;
        this->m = matrix.size();
        this->n = matrix[0].size();
        this->memo = vector(m, vector<int> (n, -1));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                result = max(result, traverse(i, j, 0));
            }
        }

        return result;
    }

private:
    int m, n;
    vector<vector<int>> matrix;
    vector<vector<int>> memo;
    int result = 0;

    int traverse(int x, int y, int prevLength){
        if(x < 0 || x >= m || y < 0 || y >= n){
            return -1;
        }
        if(memo[x][y] != -1) return memo[x][y] + prevLength;

        int returnLength = 1;
        if(x >= 1 && matrix[x-1][y] > matrix[x][y]){
            returnLength = max(returnLength, traverse(x-1, y, prevLength+1));
        }
        if(y < n-1 && matrix[x][y+1] > matrix[x][y]){
            returnLength = max(returnLength, traverse(x, y+1, prevLength+1));
        }
        if(x < m-1 && matrix[x+1][y] > matrix[x][y]){
            returnLength = max(returnLength, traverse(x+1, y, prevLength+1));
        }
        if(y >= 1 && matrix[x][y-1] > matrix[x][y]){
            returnLength = max(returnLength, traverse(x, y-1, prevLength+1));
        }

        if(returnLength != 1) memo[x][y] = returnLength - prevLength;
        else memo[x][y] = returnLength;

        return memo[x][y] + prevLength;
    }

};
