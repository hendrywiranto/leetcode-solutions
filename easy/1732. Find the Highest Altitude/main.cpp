class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int answer = 0;
        int now = 0;

        for(int i=0;i<gain.size();i++){
            answer = max(answer, now + gain[i]);
            now += gain[i];
        }

        return answer;
    }
};
