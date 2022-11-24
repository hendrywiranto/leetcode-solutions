class Solution {
public:
    bool exist(vector<vector<char>>& board, string word){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j] == word[0] && traverse(board, word, j, i, 0)) return true;
            }
        }

        return false;
    }

    bool traverse(vector<vector<char>>& board, string word, int x, int y, int i){
        if(i >= word.size()) return true;
        if(x < 0 || x >= board[0].size() || y < 0 || y >= board.size()) return false;
        if(board[y][x] != word[i]) return false;

        char temp = board[y][x];
        board[y][x] = '.';
        bool verdict = traverse(board, word, x-1, y, i+1) || traverse(board, word, x, y+1, i+1) || traverse(board, word, x+1, y, i+1) || traverse(board, word, x, y-1, i+1);
        board[y][x] = temp;

        return verdict;
    }
};
