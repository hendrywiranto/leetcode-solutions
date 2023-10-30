class Solution {

map<int,int> memo;

public:
    vector<int> sortByBits(vector<int>& arr) {
        map<int,vector<int>> countMap;
        sort(arr.begin(), arr.end());

        for(int i=0;i<arr.size();i++){
            int bits = countBits(arr[i]);
            countMap[bits].push_back(arr[i]);
        }

        vector<int> result;
        for(auto cm:countMap){
            for(auto x:cm.second){
                result.push_back(x);
            }
        }

        return result;
    }

private:
    int countBits(int n){
        if(memo.find(n) != memo.end()) return memo[n];

        int org = n;
        int result = 0;
        while(n){
            if(memo.find(n) != memo.end()){
                result += memo[n];
                break;
            }
            else if(n % 2 == 1) result++;

            n /= 2;
        }

        memo[org] = result;
        return result;
    }
};
