class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        if(deck.size() <= 2) return deck;

        vector<int> answer;
        int i = deck.size()-1;
        answer.push_back(deck[i]); i--;        
        answer.insert(answer.begin(), deck[i]); i--;

        for(;i>=0;i--){
            answer.insert(answer.begin(), answer.back());
            answer.pop_back();
            answer.insert(answer.begin(), deck[i]);            
        }

        return answer;
    }
};
