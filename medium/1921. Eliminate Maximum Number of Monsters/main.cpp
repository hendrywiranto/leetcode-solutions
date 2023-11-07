class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<int> timeNeeded;

        for(int i=0;i<dist.size();i++){
            timeNeeded.push_back(ceil(float(dist[i]) / float(speed[i])));
        }
        sort(timeNeeded.begin(), timeNeeded.end());

        int n = 0;
        while(n<timeNeeded.size()){
            if(n >= timeNeeded[n]) break;
            n++;
        }

        return n;
    }
};
