class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> freq(1001, 0);
        for(int n : arr1) freq[n]++;
        int i = 0;
        for(int n : arr2) while(freq[n]--) arr1[i++] = n;
        for(int j = 0; j<1001; j++) while(freq[j]-- > 0) arr1[i++] = j;
        return arr1;
    }
};