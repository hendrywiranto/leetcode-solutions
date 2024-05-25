class Solution {
    int matchString(string s, string word){
        int i;
        for(i=0;i<word.size() && i<s.size();i++){
            if(s[i] != word[i]) return -1;
        }
        
        if(i == word.size()) return i;
        else return -1;
    }

    bool explore(string s, vector<string>& wordDict, int l, map<string,bool> &memo){
        if(memo.find(s) != memo.end()) return memo[s];
        if(l >= s.size()) return true;

        bool verdict = false;
        for(int i=0;i<wordDict.size();i++){
            int matchIndex = matchString(s, wordDict[i]);
            if(matchIndex != -1){                
                string cut = s.substr(matchIndex, s.size()-matchIndex);
                verdict = verdict || explore(cut, wordDict, 0, memo);
            }
        }

        memo[s] = verdict;
        return verdict;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        map<string,bool> memo;

        return explore(s, wordDict, 0, memo);
    }
};
