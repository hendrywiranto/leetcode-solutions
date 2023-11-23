class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {        
        vector<bool> bools;

        for(int i=0;i<l.size();i++){
            vector<int> range;
            for(int j=l[i];j<=r[i];j++){                
                range.push_back(nums[j]);
            }
            sort(range.begin(), range.end());

            int diff = range[1] - range[0];
            bool arithmetic = true;
            for(int j=2;j<range.size();j++){
                if(diff != (range[j] - range[j-1])){
                    bools.push_back(false);
                    arithmetic = false;                    
                    break;
                }
            }
            if(arithmetic) bools.push_back(true);            
        } 

        return bools;
    }
};
