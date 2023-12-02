class Solution {
    public int countCharacters(String[] words, String chars) {
        HashMap<Character, Integer> charCountMap = new HashMap<>();

        for (char c : chars.toCharArray()) {
            charCountMap.put(c, charCountMap.getOrDefault(c, 0) + 1);
        }

        int ans = 0;

        for (String word : words) {
            HashMap<Character, Integer> currMap = new HashMap<>(charCountMap);

            boolean flag = true;
            int n = word.length();
            for (int i = 0; i < n; i++) {
                char c = word.charAt(i);

                if (currMap.containsKey(c) && currMap.get(c) > 0) {
                    currMap.put(c, currMap.get(c) - 1);
                } else {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                ans += n;
            }
        }

        return ans;
    }
}