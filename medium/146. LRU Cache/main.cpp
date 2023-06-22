class LRUCache {
struct ListNode {
    int key;
    int val;
    ListNode *next, *prev;
    ListNode() : val(0), next(nullptr), prev(nullptr) {}
    ListNode(int key, int value) : key(key), val(value), next(nullptr), prev(nullptr) {}
    ListNode(int x, ListNode *next, ListNode *prev) : val(x), next(next), prev(prev) {}
};

private:
    unordered_map<int,ListNode*> keyMap;
    ListNode *head, *tail;
    int count = 0;
    int capacity;

    void removeTail(){
        ListNode *node = tail->prev;

        node->prev->next = tail;
        tail->prev = node->prev;

        keyMap.erase(node->key);
        delete node;
        return;
    }

    void moveToHead(ListNode *node){
        removeNode(node);
        insertToHead(node);
    }

    void removeNode(ListNode *node){
        node->prev->next = node->next;
        node->next->prev = node->prev;

        node->next = nullptr;
        node->prev = nullptr;

        return;
    }

    void insertToHead(ListNode *node){
        head->next->prev = node;
        node->next = head->next;

        head->next = node;
        node->prev = head;

        return;
    }
public:
    LRUCache(int c) {
        capacity = c;
        head = new ListNode();
        tail = new ListNode();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if(keyMap.find(key) != keyMap.end()){
            moveToHead(keyMap[key]);

            return keyMap[key]->val;
        }

        return -1;
    }

    void put(int key, int value) {
        ListNode *node;
        if(keyMap.find(key) != keyMap.end()){ // found key
            keyMap[key]->val = value;
            moveToHead(keyMap[key]);
        }
        else {
            keyMap[key] = new ListNode(key, value);
            insertToHead(keyMap[key]);

            if(count >= capacity){
                removeTail();
            }
            else {
                count++;
            }
        }
        return;
    }
};
