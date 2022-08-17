class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_map<int,string> dict;
        dict[0] = ".-";
        dict[1] = "-...";
        dict[2] = "-.-.";
        dict[3] = "-..";
        dict[4] = ".";
        dict[5] = "..-.";
        dict[6] = "--.";
        dict[7] = "....";
        dict[8] = "..";
        dict[9] = ".---";
        dict[10] = "-.-";
        dict[11] = ".-..";
        dict[12] = "--";
        dict[13] = "-.";
        dict[14] = "---";
        dict[15] = ".--.";
        dict[16] = "--.-";
        dict[17] = ".-.";
        dict[18] = "...";
        dict[19] = "-";
        dict[20] = "..-";
        dict[21] = "...-";
        dict[22] = ".--";
        dict[23] = "-..-";
        dict[24] = "-.--";
        dict[25] = "--..";

        unordered_map<string,bool> memo;
        int result = 0;

        for(int i=0;i<words.size();i++){
            string s = "";

            for(int j=0;j<words[i].size();j++){
                s += dict[words[i][j] - 'a'];
            }

            if(memo.find(s) == memo.end()){
                memo[s] = true;
                result++;
            }
        }

        return result;
    }
};
