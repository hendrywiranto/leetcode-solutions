class Solution {
public:
    bool checkIfPangram(string sentence) {
        int arr[26] = { 0 };
        int distinctCount = 0;

        for(int i=0;i<sentence.size();i++){
            if(arr[sentence[i]-'a'] == 0){
                distinctCount++;
            }
            arr[sentence[i]-'a'] = 1;
        }

        return distinctCount == 26;
    }
};
