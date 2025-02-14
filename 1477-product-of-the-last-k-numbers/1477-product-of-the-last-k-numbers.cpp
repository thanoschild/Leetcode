class ProductOfNumbers {
public:
    vector<int> prefix;
    ProductOfNumbers() {
        prefix.push_back(1);
    }
    
    void add(int num) {
        if(num > 0) prefix.push_back(prefix.back() * num); 
        else prefix = {1};
    }
    
    int getProduct(int k) {
        int n = prefix.size();
        return k < n ? prefix.back() / prefix[n - 1 - k] : 0;
    }
};

// k = 3
// 1 4 10 34 55 222
// n-1 = 5, 2


/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */