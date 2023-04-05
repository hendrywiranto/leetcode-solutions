class Solution {
public:
    int countDigits(int num) {
        int tmp = num;
        int result = 0;
        while(tmp > 0){
            int digit = tmp % 10;
            if(num % digit == 0) result++;

            tmp /= 10;
        }

        return result;
    }
};
