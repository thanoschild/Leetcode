class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> arr;
        for(auto it : nums) arr.push_back(to_string(it));

        sort(arr.begin(), arr.end(), [](string &s1, string &s2) {
            return s1 + s2 > s2 + s1;
        });

        string ans = "";
        for(auto it : arr) ans += it;
        while(ans[0] == '0' && ans.length() > 1) ans.erase(0, 1);

        return ans;
    }
};