class Solution {
public:
    int check(int mid, vector<int> &a) {
        int count = 0;
        for(auto x : a) {
            count += max(0, x - mid + 1);
        }
        return count >= 3;
    }

    int maximumLength(string s) {
        int n = s.size();
        vector<vector<int>> freq(26);

        int count = 1;
        for(int i = 1; i<n; i++) {
            if(s[i] != s[i-1]) {
                freq[s[i-1] - 'a'].push_back(count);
                count = 1;
            }
            else {
                count++;
            }
        }
        freq[s.back() - 'a'].push_back(count);

        int ans = -1;
        for(int i = 0; i<26; i++) {
            if(freq[i].size() == 0) continue;
            sort(freq[i].begin(), freq[i].end());
            int start = 1, end = freq[i].back();

            while(start <= end) {
                int mid = start + (end - start)/2;
                if(check(mid, freq[i])) {
                    ans = max(ans, mid);
                    start = mid + 1;
                }
                else {
                    end = mid - 1;
                }
            }
        }

        return ans;
    }
};