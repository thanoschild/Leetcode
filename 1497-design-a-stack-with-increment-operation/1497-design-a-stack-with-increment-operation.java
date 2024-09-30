class CustomStack {
    List<Integer> stack = new ArrayList<>();
    int len, currIdx;

    public CustomStack(int maxSize) {
        len = maxSize;
        currIdx = -1;
    }
    
    public void push(int x) {
        if(stack.size() < len) {
            stack.add(x);
            currIdx++;
        }
    }
    
    public int pop() {
        if(stack.size() > 0) {
            int n = stack.get(currIdx);
            stack.remove(currIdx);
            currIdx--;
            return n;
        }
        return -1;
    }
    
    public void increment(int k, int val) {
        for(int i = 0; i<k && i < stack.size(); i++) {
            stack.set(i, stack.get(i) + val);
        }
    }
}

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack obj = new CustomStack(maxSize);
 * obj.push(x);
 * int param_2 = obj.pop();
 * obj.increment(k,val);
 */