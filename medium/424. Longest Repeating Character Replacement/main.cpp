class Solution {
private:
    int findMostChar(vector<int> &charCount){
        int most = 0;
        for(int i=0;i<charCount.size();i++){
            if(charCount[i] > charCount[most]) most = i;
        }

        return most;
    }

    int findSubtitutionNeeded(vector<int> &charCount){
        int most = findMostChar(charCount);

        int totalExcludeMost = 0;
        for(int i=0;i<charCount.size();i++){
            if(i == most) continue;

            totalExcludeMost += charCount[i];
        }

        return totalExcludeMost;
    }
public:
    int characterReplacement(string s, int k) {
        vector<int> charCount(26,0);
        int l = 0, r = 0;
        int maxLen = 0;

        while(r < s.size()){
            charCount[s[r]-'A']++;
            while(findSubtitutionNeeded(charCount) > k){
                charCount[s[l]-'A']--;
                l++;                
            }
            
            maxLen = max(maxLen, r-l+1);
            r++;
        }

        return maxLen;
    }
};
