class Solution {
public:
    string sortVowels(string s) {
        vector<int> vowelCount(10,0);
        map<char,int> vowelMap;
        int c = 0;
        vector<char> chars = { 'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u' };
        for(auto ch:chars) vowelMap[ch] = 0;

        for(int i=0;i<s.size();i++){
            if(vowelMap.find(s[i]) != vowelMap.end()) vowelMap[s[i]]++;
        }

        string result = "";
        for(int i=0;i<s.size();i++){
            if(vowelMap.find(s[i]) == vowelMap.end()) result += s[i];
            else {
                while(c < chars.size() && vowelMap[chars[c]] == 0) c++;
                vowelMap[chars[c]]--;
                result += chars[c];                
            }
        }

        return result;
    }
};
