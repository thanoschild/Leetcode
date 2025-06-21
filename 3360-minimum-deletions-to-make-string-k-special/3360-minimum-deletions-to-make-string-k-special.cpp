class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> mp;
        for(char c : word) mp[c]++;
        
        vector<int> freq;
        for(auto it : mp) freq.push_back(it.second);
        sort(freq.begin(), freq.end());
        int n = freq.size(), ans = INT_MAX;

        for(int i = 0; i<n; i++) {
            int del = 0;
            for(int j = 0; j<i; j++) del += freq[j];
            for(int j = i; j<n; j++) {
                if(freq[j] > freq[i] + k) del += freq[j] - (freq[i] + k);
            }

            ans = min(ans, del);
        }    

        return ans;
    }
};

