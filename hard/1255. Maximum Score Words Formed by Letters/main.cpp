class Solution {
private:
    int countScore(string word, vector<int> &score, unordered_map<string,int> &scoreMemo){
        if(scoreMemo.find(word) != scoreMemo.end()) return scoreMemo[word];

        int sum = 0;
        for(int i=0;i<word.size();i++){
            sum += score[word[i]-'a'];
        }

        scoreMemo[word] = sum;
        return sum;
    }

    bool canFormWord(string word, unordered_map<char,int> letterCount){
        for(int i=0;i<word.size();i++){
            letterCount[word[i]]--;
            if(letterCount[word[i]] < 0) return false;
        }

        return true;
    }

    void takeLetters(string word, unordered_map<char,int> &letterCount){
        for(int i=0;i<word.size();i++){
            letterCount[word[i]]--;            
        }
    }

    void returnLetters(string word, unordered_map<char,int> &letterCount){
        for(int i=0;i<word.size();i++){
            letterCount[word[i]]++;            
        }
    }

    int explore(vector<string>& words, unordered_map<char,int> &letterCount, vector<int>& score, unordered_map<string,int> &scoreMemo, int first){
        if(first >= words.size()) return 0;

        int take = 0, skip = 0;
        if(canFormWord(words[first], letterCount)){
            takeLetters(words[first], letterCount);
            take = countScore(words[first], score, scoreMemo) + explore(words, letterCount, score, scoreMemo, first+1);            
            returnLetters(words[first], letterCount);
        }
        skip = explore(words, letterCount, score, scoreMemo, first+1);

        return max(take, skip);
    }

public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        unordered_map<char,int> letterCount;
        unordered_map<string,int> scoreMemo;
        for(int i=0;i<letters.size();i++){
            letterCount[letters[i]]++;
        }

        return explore(words, letterCount, score, scoreMemo, 0);
    }
};
