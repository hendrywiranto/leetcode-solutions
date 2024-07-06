class Solution {
public:
    int passThePillow(int n, int time) {
        int timeToEnd = n-1;
        int timeToFirstAgain = timeToEnd * 2;

        time = time % timeToFirstAgain;
        if(time <= timeToEnd){
            return time+1;
        } else {
            time = time % timeToEnd;
            return n - time;
        }
    }
};
