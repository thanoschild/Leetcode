class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int ans = n;

        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                if(baskets[j] >= fruits[i]) {
                    ans--;
                    baskets[j] = 0;
                    break;
                }
            }
        }

        return ans;
    }
};