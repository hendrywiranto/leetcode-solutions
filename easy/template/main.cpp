class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> curr(26,0), temp(26,0);
        for(int i=0;i<words.size();i++){
            if(i==0){
                for(int j=0;j<words[i].size();j++){
                    curr[words[i][j]-'a']++;
                }
            } else {
                for(int j=0;j<words[i].size();j++){
                    int letter = words[i][j]-'a';
                    if(curr[letter] > 0){
                        curr[letter]--;
                        temp[letter]++;
                    }
                }
                curr = temp;
                temp = vector<int>(26,0);
            }
        }

        vector<string> ans;        
        for(int i=0;i<curr.size();i++){
            for(int j=0;j<curr[i];j++){
                string tmp = "";
                tmp += 'a' + i;
                ans.push_back(tmp);
            }
        }
        return ans;
    }
};
