class Solution {
public:
    string largestGoodInteger(string num) {
        char ans = 0;
        int n = num.size();
        if(n < 3) return 0;
        for(int i = 2; i<n; i++) {
            if(num[i] == num[i - 1] && num[i] == num[i - 2]) {
                ans = max(ans, num[i]);
            }
        }
        
        return ans == 0 ? "" : string(3, ans);
    }
};