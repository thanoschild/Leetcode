class MyCircularDeque {
public:
    deque<int> pq;
    int n;
    MyCircularDeque(int k) {
        n = k;
    }
    
    bool insertFront(int value) {
        if(pq.size() < n) {
            pq.push_front(value);
            return true;
        }
        return false;
    }
    
    bool insertLast(int value) {
        if(pq.size() < n) {
            pq.push_back(value);
            return true;
        }
        return false;
    }
    
    bool deleteFront() {
        if(!pq.empty()) {
            pq.pop_front();
            return true;
        }
        return false;
    }
    
    bool deleteLast() {
        if(!pq.empty()) {
            pq.pop_back();
            return true;
        }
        return false;
    }
    
    int getFront() {
        if(!pq.empty()) {
            return pq.front();
        }
        return -1;
    }
    
    int getRear() {
        if(!pq.empty()) {
            return pq.back();
        }
        return -1;
    }
    
    bool isEmpty() {
        return pq.empty();
    }
    
    bool isFull() {
        return n == pq.size();
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */