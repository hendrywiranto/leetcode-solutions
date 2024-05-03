class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> m;

        for(int i=0;i<strs.size();i++){
            string word = strs[i];
            sort(word.begin(), word.end());
            m[word].push_back(strs[i]);
        }

        vector<vector<string>> ans;
        for(auto vect:m){           
            vector<string> tmp;
            for(auto elem:vect.second) tmp.push_back(elem);
            ans.push_back(tmp);
        }

        return ans;
    }
};
