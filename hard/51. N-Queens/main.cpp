class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        this->n = n;

        occupied = vector(n, 0);

        // initiate board with all empty cell
        string temp;
        for(int i=0;i<n;i++) temp += '.';
        board = vector(n, temp);

        // start with row 0 and 0 inserted Qs
        generate(0, 0);

        return result;
    }

private:
    int n;
    vector<int> occupied;
    vector<string> board;
    vector<vector<string>> result;

    void generate(int row, int k) {
        // k is the number of inserted Qs
        // when number of inserted Qs is n, push the result
        if (k == n) {
            result.push_back(board);
            return;
        }

        for (int i=0;i<n;i++) {
            // when column already occupied, skip it
            if(occupied[i] == 1) continue;

            // below two ifs will check if there is any Q in diagonal
            // this one is for 2 top diagonals
            if(row > 0){
                int inc = 0;
                bool flag = false;
                while(row-inc >= 0 && i-inc >= 0){
                    if(board[row-inc][i-inc] == 'Q'){
                        flag = true;
                        break;
                    }
                    inc++;
                }
                if(flag) continue;
                inc = 0;
                while(row-inc >= 0 && i+inc <= n-1){
                    if(board[row-inc][i+inc] == 'Q'){
                        flag = true;
                        break;
                    }
                    inc++;
                }
                if(flag) continue;
            }
            // this one is for 2 bottom diagonals
            if(row < n-1){
                int inc = 0;
                bool flag = false;
                while(row+inc <= n-1 && i-inc >= 0){
                    if(board[row+inc][i-inc] == 'Q'){
                        flag = true;
                        break;
                    }
                    inc++;
                }
                if(flag) continue;
                inc = 0;
                while(row+inc <= n-1 && i+inc <= n-1){
                    if(board[row+inc][i+inc] == 'Q'){
                        flag = true;
                        break;
                    }
                    inc++;
                }
                if(flag) continue;
            }

            // mark as occupied, turn cell into Q
            occupied[i] = 1;
            board[row][i] = 'Q';

            generate(row+1, k+1);

            // unmark because of backtrack, return cell back to .
            occupied[i] = 0;
            board[row][i] = '.';
        }
    }

};
