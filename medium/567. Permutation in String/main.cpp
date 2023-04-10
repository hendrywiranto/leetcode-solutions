class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> m1(26,0), m2(26,0);
        int l = 0, r = 0;

        for(auto s:s1) m1[s-'a']++;
        while(r < s2.size()){
            m2[s2[r]-'a']++;
            if(checkPalindrome(m1, m2)) return true;

            if(r < s1.size()-1){
                r++;
            }
            else {
                m2[s2[l]-'a']--;
                l++;
                r++;
            }
        }

        return false;
    }

    bool checkPalindrome(vector<int> m1, vector<int> m2){
        for(int i=0;i<26;i++){
            if(m1[i] != m2[i]) return false;
        }

        return true;
    }
};
