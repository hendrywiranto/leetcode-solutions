class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        map<int,int> changes;
        changes[5] = 0;
        changes[10] = 0;
        changes[20] = 0;

        for(int i=0;i<bills.size();i++){
            if(bills[i] == 20){
                if(changes[10] >= 1 && changes[5] >= 1){
                    changes[10]--;
                    changes[5]--;
                }
                else if(changes[5] >= 3){
                    changes[5] -= 3;
                }
                else return false;

                changes[20]++;
            }
            else if(bills[i] == 10){
                if(changes[5] >= 1) changes[5]--;
                else return false;

                changes[10]++;
            }
            else changes[5]++;
        }

        return true;
    }
};
