class Solution {
public:
    string removeStars(string s) {
        int starCount = 0;
        vector<int> m1(s.size(), 0);
        for(int i=s.size()-1;i>=0;i--){
            if(s[i] == '*'){
                starCount++;
                m1[i] = 1;
            }
            else {
                if(starCount > 0){
                    m1[i] = 1;
                    starCount--;
                }
            }
        }

        string result = "";
        for(int i=0;i<s.size();i++){
            if(m1[i] == 0) result += s[i];
        }

        return result;
    }
};
