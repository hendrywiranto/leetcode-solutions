class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<int> lib[26];
        int result = 0;
        unordered_map<string,bool> memory;

        for(int i=0;i<s.size();i++){
            lib[s[i] - 'a'].push_back(i);
        }

        for(int i=0;i<words.size();i++){
            if(memory.find(words[i]) != memory.end()){
                if(memory[words[i]]) result++;
                continue;
            };

            int lastIndex = -1;
            int violated = 0;

            for(int j=0;j<words[i].size();j++){
                vector<int> v = lib[words[i][j]-'a'];

                if(v.size() == 0){
                    violated = 1;
                    break;
                }

                vector<int>::iterator low = lower_bound(v.begin(), v.end(), lastIndex);

                if(low != v.end()){
                    lastIndex = *low + 1;
                }
                else {
                    violated = 1;
                    break;
                }
            }

            if(violated == 0){
                memory[words[i]] = true;
                result++;
            }
            else {
                memory[words[i]] = false;
            }
        }

        return result;
    }
};
