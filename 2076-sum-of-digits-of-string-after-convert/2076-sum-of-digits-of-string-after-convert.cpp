class Solution {
public:
    int getLucky(string s, int k) {
        string num = "";
        for(char c : s) num += to_string((c - 'a') + 1);

        while(k--) {
            int temp = 0;
            for(char c : num) temp += (c - '0');
            num = to_string(temp);
        }

        return stoi(num);
    }
};