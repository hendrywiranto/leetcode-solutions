class BrowserHistory {
private:
struct ListNode {
    string url;
    ListNode *next;
    ListNode *prev;

    ListNode(): url(""), next(nullptr), prev(nullptr) {};
    ListNode(string url, ListNode *next, ListNode *prev): url(url), next(next), prev(prev) {};
};

ListNode *curr;

public:
    BrowserHistory(string homepage) {
        curr = new ListNode(homepage, nullptr, nullptr);
    }

    void visit(string url) {
        ListNode *newNode = new ListNode(url, nullptr, curr);
        curr->next = newNode;
        curr = newNode;

        return;
    }

    string back(int steps) {
        int i = 0;
        while(i<steps && curr->prev != nullptr){
            curr = curr->prev;
            i++;
        }

        return curr->url;
    }

    string forward(int steps) {
        int i = 0;
        while(i<steps && curr->next != nullptr){
            curr = curr->next;
            i++;
        }

        return curr->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
