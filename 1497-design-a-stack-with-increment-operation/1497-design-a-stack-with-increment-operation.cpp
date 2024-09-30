class CustomStack {
public:
    vector<int> stack;
    int len;
    CustomStack(int maxSize) {
        len = maxSize;
    }
    
    void push(int x) {
        if(stack.size() < len) {
            stack.push_back(x);
        }
    }
    
    int pop() {
        if(stack.size() > 0) {
            int n = stack.back();
            stack.pop_back();
            return n;
        }
        return -1;
    }
    
    void increment(int k, int val) {
        for(int i = 0; i<k && i < stack.size(); i++) {
            stack[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */