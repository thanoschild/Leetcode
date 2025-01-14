class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size(), count = 0;
        vector<int> freq(n + 1, 0), ans;

        for(int i = 0; i<n; i++) {
            if(++freq[A[i]] == 2) count++;
            if(++freq[B[i]] == 2) count++;
            ans.push_back(count);
        }

        return ans;
    }
};