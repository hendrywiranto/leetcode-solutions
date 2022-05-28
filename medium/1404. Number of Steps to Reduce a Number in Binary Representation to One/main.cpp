class Solution {
public:
    int numSteps(string s) {
        int result = 0;

        while(s.size() > 1){
            if(s[s.size()-1] == '0'){
                s.pop_back();
                result++;
            }
            else {
                int i = 1;
                while(i <= s.size() && s[s.size()-i] == '1'){
                    s[s.size()-i] = '0';
                    i++;
                }
                if(i > s.size()) s = '1' + s;
                else s[s.size()-i] = '1';
                result++;
            }
        }

        return result;
    }
};
