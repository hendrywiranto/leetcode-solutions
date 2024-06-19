class Solution {
private:
    int countBouquet(vector<int>& bloomDay, int k, int day){        
        int len = 0;
        int ctr = 0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i] <= day) len++;
            else len = 0;

            if(len == k){
                ctr++;
                len = 0;
            }
        }

        return ctr;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {        
        int maxDays = 0;
        for(int i=0;i<bloomDay.size();i++){
            maxDays = max(maxDays, bloomDay[i]);
        }

        int l = 0, r = maxDays;
        int mid;
        int ans = -1;
        while(l <= r){
            mid = l + (r-l) / 2;
            int ctr = countBouquet(bloomDay, k, mid);
            if(ctr < m){
                l = mid+1;
            }
            else if(ctr >= m){
                r = mid-1;
                ans = mid;
            }
        }

        return ans;
    }
};
