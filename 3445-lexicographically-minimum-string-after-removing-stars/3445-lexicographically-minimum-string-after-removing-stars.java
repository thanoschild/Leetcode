class Solution {
    public String clearStars(String s) {
        int n = s.length();
        PriorityQueue<Character> pq = new PriorityQueue<>();
        HashMap<Character, Deque<Integer>> mp = new HashMap<>();
        boolean[] check = new boolean[n];
        Arrays.fill(check, true);

        for(int i = 0; i<n; i++) {
            char c = s.charAt(i);
            if(c == '*') {
                char temp = pq.poll();
                int idx = mp.get(temp).removeLast();
                check[i] = false;
                check[idx] = false;
            } else {
                pq.offer(c);
                mp.putIfAbsent(c, new ArrayDeque<>());
                mp.get(c).add(i);
            }
        }

        StringBuilder ans = new StringBuilder();
        for(int i = 0; i<n; i++) {
            if(check[i]) ans.append(s.charAt(i));
        }

        return ans.toString();
    }
}