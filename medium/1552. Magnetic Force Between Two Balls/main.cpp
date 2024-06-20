class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int l = 0, r = position.back() - position.front();
        int mid;
        int ans;
        while(l <= r){            
            mid = l + (r-l)/2;
            if(countBalls(position, mid) >= m){
                l = mid+1;                
                ans = mid;
            }
            else {
                r = mid-1;
            }
        }

        return ans;
    }

private:
    int countBalls(vector<int>& position, int d){
        int ans = 1, curr = position[0];
        for(int i=1;i<position.size();i++){
            if(position[i] - curr >= d){
                ans++;
                curr = position[i];
            }
        }

        return ans;
    }
};
