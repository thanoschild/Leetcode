class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mp;
        for(string s : strs) {
            string original = s;
            sort(s.begin(), s.end());
            mp[s].push_back(original);
        }

        vector<vector<string>> ans;
        for(auto it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};