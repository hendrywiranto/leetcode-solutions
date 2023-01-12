class MedianFinder {
    priority_queue<int> small, large;
    int n = 0;
    int median;
public:
    MedianFinder() {

    }

    void addNum(int num) {
        n++;
        if(n == 1){
            median = num;
            return;
        }
        if(n % 2 == 1){
            if(small.top() >= num){
                small.push(num);
                median = small.top();
                small.pop();
            }
            else {
                large.push(num * -1);
                median = large.top() * -1;
                large.pop();
            }
        }
        else {
            if(num <= median){
                small.push(num);
                large.push(median * -1);
            }
            else {
                small.push(median);
                large.push(num * -1);
            }
        }
    }

    double findMedian() {
        if(n % 2 == 1) return median;
        else return float(small.top() + large.top()*-1) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
