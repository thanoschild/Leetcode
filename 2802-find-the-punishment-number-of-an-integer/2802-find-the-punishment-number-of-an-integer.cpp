class Solution {
public:
    bool checkNum(int num, int target) {
        if(target < 0 || num < target) return false;
        if(num == target) return true;

        return checkNum(num/10, target - num % 10) || checkNum(num/100, target - num % 100) || 
        checkNum(num/1000, target - num % 1000);
    }
    
    int punishmentNumber(int n) {
        int ans = 0;
        for(int i = 1; i<=n; i++) {
            int num = i * i;
            if(checkNum(num, i)) ans += num;
        }

        return ans;
    }
};