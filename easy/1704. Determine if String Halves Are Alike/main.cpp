class Solution {
public:
    bool halvesAreAlike(string s) {
        int vow_left = 0, vow_right = 0;
        for(int i=0;i<s.size();i++){
            if(i < s.size()/2){
                if(s[i] == 'a' ||
                  s[i] == 'e' ||
                  s[i] == 'i' ||
                  s[i] == 'o' ||
                  s[i] == 'u' ||
                  s[i] == 'A' ||
                  s[i] == 'E' ||
                  s[i] == 'I' ||
                  s[i] == 'O' ||
                  s[i] == 'U'){
                    vow_left++;
                }
            }
            else {
                if(s[i] == 'a' ||
                  s[i] == 'e' ||
                  s[i] == 'i' ||
                  s[i] == 'o' ||
                  s[i] == 'u' ||
                  s[i] == 'A' ||
                  s[i] == 'E' ||
                  s[i] == 'I' ||
                  s[i] == 'O' ||
                  s[i] == 'U'){
                    vow_right++;
                }
            }
        }

        return vow_left == vow_right;
    }
};
