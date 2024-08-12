class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int limit;
    KthLargest(int k, vector<int>& nums) {
        limit = k;
        for(int n : nums) pq.push(n);
    }
    
    int add(int val) {
        pq.push(val);
        while(pq.size() > limit) pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */