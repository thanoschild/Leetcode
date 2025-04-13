class Solution {
public:
    const int mod = 1e9 + 7;
    long long binaryExpo(long long a, long long b) {
        long long ans = 1;
        while(b) {
            if(b & 1) ans = (ans * a) % mod;
            a = (a * a) % mod;
            b /= 2;
        }

        return ans;
    }

    int countGoodNumbers(long long n) {
        return (binaryExpo(4, n/2) * binaryExpo(5, n - n/2)) % mod;
    }
};