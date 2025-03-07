class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> sieve(right + 1, true);
        sieve[0] = sieve[1] = false;

        for(int i = 2; i*i<=right; i++) {
            if(sieve[i]) {
                for(int j = i*i; j<=right; j += i) {
                    sieve[j] = false;
                }
            }
        }

        vector<int> primes;
        for(int i = left; i<=right; i++) {
            if(sieve[i]) primes.push_back(i);
        }

        if(primes.size() < 2) return {-1, -1};

        int gap = INT_MAX;
        vector<int> ans = {-1, -1};
        for(int i = 1; i<primes.size(); i++) {
            int curr = primes[i] - primes[i-1];
            if(gap > curr) {
                gap = curr;
                ans = {primes[i-1], primes[i]};
            }
        }

        return ans;
    }
};