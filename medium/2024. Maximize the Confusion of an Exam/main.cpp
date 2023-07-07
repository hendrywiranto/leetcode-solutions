class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int left = 0;
        int right = 0;
        map<char,int> charCount;
        int answer = 0;

        charCount[answerKey[right]]++;

        while(right < answerKey.size() && left <= right){
            int minChar = min(charCount['T'], charCount['F']);

            if(minChar <= k){
                answer = max(answer, right - left + 1);
                right++;
                charCount[answerKey[right]]++;
            }
            else {
                charCount[answerKey[left]]--;
                left++;
            }
        }
        return answer;
    }
};
