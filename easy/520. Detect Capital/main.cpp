class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.size() == 1) return true;

        bool caps  = false;
        bool allCaps = false, firstCaps = false;
        if(word[0] < 97){
            caps = true;
            if(word[1] < 97) allCaps = true;
            else firstCaps = true;
        }

        for(int i=1;i<word.size();i++){
            if(caps){
                if(allCaps && word[i] >= 97) return false;
                else if(firstCaps && word[i] < 97) return false;
            }
            else {
                if(word[i] < 97) return false;
            }
        }

        return true;
    }
};
