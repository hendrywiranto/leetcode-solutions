class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        vector<pair<int,int>> sortedCourses;

        for(int i=0;i<courses.size();i++){
            sortedCourses.push_back(make_pair(courses[i][1], courses[i][0]));
        }
        sort(sortedCourses.begin(), sortedCourses.end());

        priority_queue<int> pq;
        int result = 0;
        int time = 0;
        for(int i=0;i<sortedCourses.size();i++){
            if(sortedCourses[i].second + time <= sortedCourses[i].first){
                time += sortedCourses[i].second;
                pq.push(sortedCourses[i].second);
            }
            else if (!pq.empty() && pq.top() > sortedCourses[i].second){
                time += sortedCourses[i].second - pq.top();
                pq.pop();
                pq.push(sortedCourses[i].second);
            }
        }

        return pq.size();
    }
};
