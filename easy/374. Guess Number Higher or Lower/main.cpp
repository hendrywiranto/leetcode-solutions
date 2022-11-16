/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int low = 1, high = INT_MAX;
        while(1){
            int g = guess(n);
            if(g == 0) return n;
            else if(g == 1){
                low = n;
                n += (high - low)/2;
            }
            else {
                high = n;
                n = low + (high - low)/2;
            }
        }
    }
};
