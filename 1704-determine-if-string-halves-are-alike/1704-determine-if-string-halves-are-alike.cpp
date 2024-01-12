class Solution {
public:
    bool halvesAreAlike(string s) {
        char arr[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        set<char> st(arr, arr + 10);
        int count1 = 0, count2 = 0;
        int n = s.size();

        for(int i = 0; i<n/2; i++) {
            if(st.find(s[i]) != st.end()) count1++;
            if(st.find(s[i + n/2]) != st.end()) count2++;
        }

        return count1 == count2;
    }
};