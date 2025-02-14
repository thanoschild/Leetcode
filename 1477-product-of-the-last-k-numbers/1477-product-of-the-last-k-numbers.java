class ProductOfNumbers {
    List<Integer> prefix = new ArrayList<>();
    public ProductOfNumbers() {
        prefix.add(1);
    }
    
    public void add(int num) {
        if(num > 0) prefix.add(prefix.get(prefix.size() - 1) * num);
        else {
            prefix = new ArrayList<>();
            prefix.add(1);
        }
    }
    
    public int getProduct(int k) {
        int n = prefix.size();
        return k < n ? prefix.get(n - 1) / prefix.get(n - 1 - k) : 0;
    }
}

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers obj = new ProductOfNumbers();
 * obj.add(num);
 * int param_2 = obj.getProduct(k);
 */