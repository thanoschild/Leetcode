class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0) return false;
        map<int ,int> mp;
        for(int n : hand) {
            mp[n]++;
        }

        for(auto[it, val] : mp) {
            if(mp[it] > 0) {
                for(int i = groupSize-1; i>=0; i--) {
                    if(mp[it + i] < mp[it]) return false;
                    else mp[it+i] -= mp[it];
                }
            }
        }

        return true;
    }
};