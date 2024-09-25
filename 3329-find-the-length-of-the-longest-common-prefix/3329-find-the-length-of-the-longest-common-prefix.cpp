class Solution {
public:
    int find_len(int n) {
        string s = to_string(n);
        return s.size();
    }
    
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st;
        for(int n : arr1) {
            while(n > 0) {
                st.insert(n);
                n/=10;
            }
        }

        int ans = 0;
        for(int n : arr2) {
            while(n > 0) {
                if(st.find(n) != st.end()) {
                    ans = max(ans, find_len(n));
                }
                n /= 10;
            }
        }

        return ans;
    }
};