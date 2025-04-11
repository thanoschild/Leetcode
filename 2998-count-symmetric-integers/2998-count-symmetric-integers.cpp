class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for(int i = low; i<=high; i++) {
            string s = to_string(i);
            int n = s.size();
            if(n%2) continue;
            int total = 0;
            for(int j = 0; j< n/2; j++) {
                total += (s[j] - '0') - (s[j + n/2] - '0');
            }
            if(total == 0) count++;
        } 
        return count;
    }
};