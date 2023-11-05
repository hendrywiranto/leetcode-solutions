class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int curr = arr[0];
        int wins = 0;

        for(int i=1;i<arr.size();i++){
            if(arr[i] > curr){
                curr = arr[i];
                wins = 1;
            }
            else {                
                wins++;
            }

            if(wins == k) break;
        }

        return curr;
    }
};
