class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> m1;

        for(int i=0;i<strs.size();i++){
            m1[countingSort(strs[i])].push_back(strs[i]);
        }

        vector<vector<string>> result;
        for(auto m:m1) result.push_back(m.second);

        return result;
    }
private:
    string countingSort(string s) {
        int counter[26] = {0};
        for (char c : s) {
            counter[c - 'a']++;
        }
        string t;
        for (int c = 0; c < 26; c++) {
            t += string(counter[c], c + 'a');
        }
        return t;
    }
};
