class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = 0, mid = 0, ans = 0;;
        for(auto p:piles) r = max(r, p);
        while(l <= r){
            mid = l + (r - l) / 2;
            if(canEatAllBananas(piles, mid, h)){
                ans = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        return ans;
    }

    bool canEatAllBananas(vector<int> piles, int k, int h){
        long long int days = 0;
        int i = 0;
        while(i < piles.size()){
            int now = piles[i] / k;
            days += (piles[i] % k) == 0 ? now : now + 1;
            i++;
        }
        return days <= h;
    }
};
