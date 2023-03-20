class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int ctr = 0;

        for(int i=0;i<flowerbed.size();i++){
            if(flowerbed[i] == 1) i++;

            if(i-1 >= 0 && flowerbed[i-1] == 1) continue;
            if(i+1 < flowerbed.size() && flowerbed[i+1] == 1) continue;

            flowerbed[i] = 1;
            ctr++;
        }

        return ctr >= n;
    }
};
