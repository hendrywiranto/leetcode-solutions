class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {      
        int prefixSum = 0;  
        int result = 0;
        int distM = 0, distP = 0, distG = 0;

        for(int i=0;i<garbage.size();i++){    
            if(i != 0) prefixSum += travel[i-1];
            
            result += garbage[i].size();
            for(int j=0;j<garbage[i].size();j++){                
                if(garbage[i][j] == 'M') distM = prefixSum;
                else if(garbage[i][j] == 'P') distP = prefixSum;
                else if(garbage[i][j] == 'G') distG = prefixSum;
            }                
        }            

        return result + distM + distP + distG;
    }
};
