class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;
        int i = 1;
        int bricksNow = 0;
        int ladderNow = 0;

        while(i < heights.size()){
            if(heights[i] > heights[i-1]) {
                int diff = heights[i] - heights[i-1];

                bricksNow += diff;
                pq.push(diff);

                if(bricksNow > bricks){
                    if(ladderNow == ladders) break;

                    int pqTop = pq.top();
                    pq.pop();
                    bricksNow -= pqTop;
                    ladderNow++;
                }
            }

            i++;
        }

        return i-1;
    }
};
