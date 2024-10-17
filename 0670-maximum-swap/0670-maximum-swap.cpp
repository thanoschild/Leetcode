class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        for(int i = 0; i<s.size(); i++) {
            auto it = max_element(s.rbegin(), s.rend() - i);
            if(s[i] != *it) {
                swap(s[i], *it);
                break;
            }
        }

        return stoi(s);
    }
};