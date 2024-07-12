class Solution {
    public int maximumGain(String s, int x, int y) {
        String top, bot;
        int topScore, botScore;

        if (x > y) {
            top = "ab";
            topScore = x;
            bot = "ba";
            botScore = y;
        } else {
            top = "ba";
            topScore = y;
            bot = "ab";
            botScore = x;
        }

        Stack<Character> stack = new Stack<>();
        int ans = 0;
        for (char c : s.toCharArray()) {
            if (c == top.charAt(1) && !stack.isEmpty() && stack.peek() == top.charAt(0)) {
                ans += topScore;
                stack.pop();
            } else {
                stack.push(c);
            }
        }

        Stack<Character> stack1 = new Stack<>();
        for (char c : stack) {
            if (c == bot.charAt(1) && !stack1.isEmpty() && stack1.peek() == bot.charAt(0)) {
                ans += botScore;
                stack1.pop();
            } else {
                stack1.push(c);
            }
        }

        return ans;
    }
}