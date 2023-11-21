class Solution {
private:
    int rev(map<int,int> &revMap, int n) {
        if(revMap.find(n) != revMap.end()) return revMap[n];

        string str = to_string(n);
        reverse(str.begin(), str.end());

        revMap[n] = stoi(str);

        return revMap[n];
    }

    long long int calcPair(long long int freq) {
        return (freq * (freq - 1) / 2);
    }
public:
    int countNicePairs(vector<int>& nums) {
        map<int,int> resultMap;
        map<int,int> revMap;
        
        for(int i=0;i<nums.size();i++){
            resultMap[nums[i] - rev(revMap, nums[i])]++;            
        }

        int result = 0;
        for(auto rm:resultMap){
            result = (result + calcPair(rm.second)) % 1000000007;
        }

        return result;
    }
};
