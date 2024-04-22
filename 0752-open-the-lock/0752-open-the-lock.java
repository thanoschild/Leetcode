class Solution {
    public List<String> possibleWays(String str) {
        List<String> ways = new ArrayList<>();
        for (int i = 0; i < 4; i++) {
            StringBuilder curr = new StringBuilder(str);
            if (curr.charAt(i) == '9') curr.setCharAt(i, '0');
            else curr.setCharAt(i, (char) (curr.charAt(i) + 1));
            ways.add(curr.toString());

            curr = new StringBuilder(str);
            if (curr.charAt(i) == '0') curr.setCharAt(i, '9');
            else curr.setCharAt(i, (char) (curr.charAt(i) - 1));
            ways.add(curr.toString());
        }
        return ways;
    }

    public int openLock(String[] deadends, String target) {
        if (target.equals("0000")) return 0;
        Set<String> check = new HashSet<>(Arrays.asList(deadends));
        Set<String> visited = new HashSet<>();
        Queue<String> pq = new LinkedList<>();
        pq.offer("0000");
        int ans = 0;

        while (!pq.isEmpty()) {
            int n = pq.size();
            for (int i = 0; i < n; i++) {
                String curr = pq.poll();

                if (curr.equals(target)) return ans;
                if (visited.contains(curr) || check.contains(curr)) continue;

                List<String> ways = possibleWays(curr);
                for (String s : ways) pq.offer(s);
                visited.add(curr);
            }
            ans++;
        }

        return -1;
    }
}