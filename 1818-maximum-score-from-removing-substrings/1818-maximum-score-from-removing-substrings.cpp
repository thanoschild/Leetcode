class Solution {
public:
    int maximumGain(string s, int x, int y) {
        string top, bot;
        int top_score, bot_score;

        if(x > y) {
            top = "ab";
            top_score = x;
            bot = "ba";
            bot_score = y;
        }
        else {
            top = "ba";
            top_score = y;
            bot = "ab";
            bot_score = x;
        }

        vector<char> stack;
        int ans = 0;
        for(char c : s) {
            if(c == top[1] && !stack.empty() && stack.back() == top[0]) {
               ans += top_score;
               stack.pop_back();
            }
            else {
                stack.push_back(c);
            }
        }

        vector<char> stack1;
        for(char c : stack) {
            if(c == bot[1] && !stack1.empty() && stack1.back() == bot[0]) {
                ans += bot_score;
                stack1.pop_back();
            }
            else {
                stack1.push_back(c);
            }
        }

        return ans;
    }
};