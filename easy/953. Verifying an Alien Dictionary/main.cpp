class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> dict(26, 0);
        int last = 0;

        for(int i=0;i<order.size();i++) dict[order[i] - 'a'] = i;
        for(int i=0;i<words.size();i++){
            if(i + 1 >= words.size()) break;

            for(int j=0;j<words[i].size();j++){
                if(j >= words[i+1].size()) return false;

                if(dict[words[i][j] - 'a'] == dict[words[i+1][j] - 'a']) continue;
                else if(dict[words[i][j] - 'a'] < dict[words[i+1][j] - 'a']) break;
                else return false;
            }

        }

        return true;
    }
};
