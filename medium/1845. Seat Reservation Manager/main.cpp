class SeatManager {
private:
    priority_queue<int> pq;

public:
    SeatManager(int n) {
        for(int i=1;i<=n;i++){
            pq.push(i * -1);
        }
    }
    
    int reserve() {
        int tmp = pq.top();
        pq.pop();

        return tmp * -1;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber * -1);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
