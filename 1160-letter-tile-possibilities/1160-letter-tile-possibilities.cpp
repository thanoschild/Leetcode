class Solution {
public:
    int dfs(vector<int> &arr) {
        int count = 0;
        for(int i = 0; i<26; i++) {
            if(arr[i] == 0) continue;
            count++;
            arr[i]--;
            count += dfs(arr);
            arr[i]++;
        }
        return count;
    }

    int numTilePossibilities(string tiles) {
        vector<int> freq(26, 0);
        for(char c : tiles) freq[c - 'A']++;
        return dfs(freq);
    }
};