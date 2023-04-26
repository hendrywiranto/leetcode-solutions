class Solution {
public:
    int addDigits(int num) {
        while(num >= 10){
            int newNum = 0;
            while(num > 0){
                newNum += num % 10;
                num /= 10;
            }
            num = newNum;
        }

        return num;
    }
};
