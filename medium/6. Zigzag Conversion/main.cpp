class Solution {
public:
    string convert(string str, int numRows) {
        vector<string> rows(numRows);
        bool up = true;
        int i = 0;

        for(auto s:str){
            rows[i] += s;

            if(numRows == 1) continue;
            if(up){
                if(i == numRows-1) { up = false; i--; }
                else i++;
            }
            else {
                if(i == 0) { up = true; i++; }
                else i--;
            }
        }
        string ans = "";
        for(auto r:rows) ans += r;

        return ans;
    }
};
