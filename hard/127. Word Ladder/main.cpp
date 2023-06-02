class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        int result = 0;
        unordered_set<string> dict(wordList.begin(), wordList.end());

        q.push(make_pair(beginWord, 1));
        while(!q.empty()){
            pair<string,int> curr = q.front();
            string word = curr.first;
            int ctr = curr.second;
            if(word == endWord) return ctr;

            dict.erase(word);

            for(int i=0;i<word.size();i++){
                int oriChar = word[i];
                int ac = 0;

                word[i] = 'a';
                while(ac < 26){
                    if(dict.find(word) != dict.end()){
                        q.push(make_pair(word, ctr+1));
                    }
                    word[i]++;
                    ac++;
                }
                word[i] = oriChar;
            }
            q.pop();
        }

        return 0;
    }
};
