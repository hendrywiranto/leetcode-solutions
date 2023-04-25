class SmallestInfiniteSet {
private:
    vector<bool> memo;
    priority_queue<int> pq;

public:
    SmallestInfiniteSet() {
        memo.resize(1001, true);
        for(int i=1;i<=1000;i++) pq.push(i * -1);
    }

    int popSmallest() {
        int smallest = pq.top() * -1; pq.pop();
        memo[smallest] = false;

        return smallest;
    }

    void addBack(int num) {
        if(!memo[num]){
            memo[num] = true;
            pq.push(num * -1);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
