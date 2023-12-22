class Solution {
private:
    int countChars(char c, string s, int start, int end){
        int ctr = 0;
        for(int i=start;i<=end;i++){
            if(c == s[i]) ctr++;
        }

        return ctr;
    }

public:
    int maxScore(string s) {
        int left = countChars('0', s, 0, 0);
        int right = countChars('1', s, 1, s.size()-1);
        int result = left+right;

        for(int i=1;i<s.size()-1;i++){
            if(s[i] == '1'){
                right--;
            } else {
                left++;
            }                    
            result = max(result, left+right);
        }

        return result;
    }
};
