class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;
        for(auto x : nums) {
            int count = 0, sum = 0;
            for(int i = 1; i*i<=x; i++) {
                if(x % i == 0) {
                    int j = x / i;
                    count++;
                    sum += i;

                    if(i != j) {
                        count++;
                        sum += j;
                    }

                    if(count > 4) break;
                }
            }

            if(count == 4) ans += sum;
        }

        return ans;
    }
};