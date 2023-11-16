class Solution {
private:
    string toString(int n, int sz){        
        string str = "";        
        while(n > 0){
            if(n % 2 == 0) str = '0' + str;
            else str = '1' + str;

            n /= 2;
        }

        while(str.size() < sz){
            str = '0' + str;
        }
        return str;
    }
public:
    string findDifferentBinaryString(vector<string>& nums) {
        map<string,bool> memo;

        for(int i=0;i<nums.size();i++){
            memo[nums[i]] = true;
        }

        for(int i=0;i<pow(2, nums.size());i++){
            string str = toString(i, nums.size());
            if(memo.find(str) == memo.end()) return str;
        }

        return "";
    }
};
