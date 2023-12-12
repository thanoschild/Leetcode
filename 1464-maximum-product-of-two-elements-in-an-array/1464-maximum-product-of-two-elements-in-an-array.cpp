class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int num1 = 0, num2 = 0;
        for(int n : nums) {
            if(n > num1) {
                num2 = exchange(num1, n);
            }
            else {
                num2 = max(num2, n);
            }
        }
        
        return (num1 - 1)*(num2 - 1);
    }
};