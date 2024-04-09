class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int target = tickets[k], time = 0;;

        for(int i=0;i<tickets.size();i++){
            time += min(target, tickets[i]);

            if(i == k) target--;   
        }

        return time;
    }
};
