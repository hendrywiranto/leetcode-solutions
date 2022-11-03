class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int> diff;
        map<string,int> same;

        int res = 0;

        for(int i=0;i<words.size();i++){
            auto temp = std::string(1, words[i][1])+words[i][0];

            if(diff.find(temp) != diff.end() && diff[temp] != 0){
                if(words[i][0] == words[i][1]) same.erase(words[i]);
                diff[temp]--;
                res += 4;
            }
            else {
                diff[words[i]]++;
                if(words[i][0] == words[i][1]) same[words[i]]++;
            }
        }

        for (auto x: same) {
            if(x.second % 2 == 1){
                res += 2;
                break;
            }
        }

        return res;
    }
};
