class Solution {
public:
    double average(vector<int>& salary) {
        double total = 0;
        int minSalary = INT_MAX, maxSalary = INT_MIN;

        for(auto s:salary){
            total += s;
            minSalary = min(minSalary, s);
            maxSalary = max(maxSalary, s);
        }

        total -= (minSalary + maxSalary);
        return total / (salary.size() - 2);
    }
};
