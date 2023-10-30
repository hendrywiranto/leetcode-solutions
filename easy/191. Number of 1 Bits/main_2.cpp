class Solution {
public:
    int hammingWeight(uint32_t n) {
        int result = 0;
        cout << n << endl;
        while(n){
            if(n % 2 == 1) result++;

            n >>= 1;
        }

        return result;
    }
};
