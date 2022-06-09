class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, last = numbers.size()-1;

        while(i < last){
            int pair = target - numbers[i];

            while(last > i){
                if(numbers[last] == pair) return { i+1, last+1};
                else if(numbers[last] < pair) break;
                last--;
            }

            i++;
        }

        return {};
    }
};
