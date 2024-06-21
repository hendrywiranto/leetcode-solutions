class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int l = 0, r = minutes-1;
        int maxS = 0;
        for(int i=0;i<customers.size();i++){
            if(i < minutes) maxS += customers[i];
            else if(grumpy[i] == 0) maxS += customers[i];
        }
        
        int ans = maxS;
        while(r < customers.size()){ 
            if(grumpy[l] == 1) maxS -= customers[l];
            l++;
            r++;
            if(r == customers.size()) break;
            if(grumpy[r] == 1) maxS += customers[r];       
            ans = max(ans, maxS);          
        }

        return ans;
    }
};
