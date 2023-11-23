class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = l.size();
        vector<bool> ans;
        for(int i = 0; i<n; i++) {
            vector<int> v = vector<int>(nums.begin() + l[i], nums.begin() + r[i] + 1);
            sort(v.begin(), v.end());
            bool flag = true;
            
            if(v.size() > 1) {
                int diff = v[1] - v[0];
                for(int i = 1; i<v.size() - 1; i++) {
                    if(v[i+1] - v[i] != diff) {
                        flag = false;
                        break;
                    }
                }
            }
            else flag = false;
            ans.push_back(flag);
        }
        
        return ans;
    }
};