class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0, j = 0;
        string result = "";

        while(i < word1.size() && j < word2.size()){
            if(i == j){
                result += word1[i];
                i++;
            }
            else {
                result += word2[j];
                j++;
            }
        }

        while(i < word1.size()){
            result += word1[i];
            i++;
        }
        while(j < word2.size()){
            result += word2[j];
            j++;
        }

        return result;
    }
};
