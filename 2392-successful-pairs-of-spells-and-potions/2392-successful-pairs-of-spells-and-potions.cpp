class Solution {
public:
    int findPosition(int spell, vector<int> &potions, long long success) {
        int start = 0, end = potions.size() - 1;
        int ans = -1;
        while(start <= end) {
            int mid = (end - start) / 2 + start;
            long long currVal = (long) potions[mid] * spell;
            if(currVal >= success) {
               ans = mid;
               end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return ans;
    }

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int m = potions.size();
        vector<int> ans;

        for(auto it : spells) {
            int position = findPosition(it, potions, success);
            if(position == -1) ans.push_back(0);
            else {
               ans.push_back(m - position);
            }
        }

        return ans;
    }
};