class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int p = 0, i = 0;
        map<char,string> m1;
        map<string,char> m2;

        string word = "";
        for(;i<s.size()+1;i++){
            if (i == s.size() || s[i] == ' ')
            {
                cout << word << endl;
                if(m1.find(pattern[p]) != m1.end() && m1[pattern[p]] != word) return false;
                if(m2.find(word) != m2.end() && m2[word] != pattern[p]) return false;
                m1[pattern[p]] = word;
                m2[word] = pattern[p];
                p++;
                if(p == pattern.size()) break;
                word = "";
            }
            else {
                word = word + s[i];
            }
        }

        return p == pattern.size() && i == s.size();
    }
};
