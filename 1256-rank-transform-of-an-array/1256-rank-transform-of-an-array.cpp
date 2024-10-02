class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int,int> mp;
        set<int> st(arr.begin(), arr.end());
        
        int rank = 1;

        for(auto it : st) {
           mp[it] = rank;
           rank++;
        }

        vector<int> ans;
        for(auto it : arr) {
            ans.push_back(mp[it]);
        }

        return ans;
    }
};