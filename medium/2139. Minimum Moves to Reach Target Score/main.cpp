class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int result = 0;

        while(target > 1){
            if(maxDoubles > 0 && target % 2 == 0){
                target /= 2;
                maxDoubles--;
                result++;
            }
            else if(maxDoubles == 0){
                result += target - 1;
                break;
            }
            else {
                target--;
                result++;
            }
        }

        return result;
    }
};
