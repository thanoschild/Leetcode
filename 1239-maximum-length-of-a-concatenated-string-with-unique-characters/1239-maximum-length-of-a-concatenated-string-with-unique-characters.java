class Solution {
    public int maxLength(List<String> arr) {
        List<BitSet> dp = new ArrayList<>();
        dp.add(new BitSet());
        int ans = 0;

        for(String s : arr) {
            BitSet st = new BitSet();
            for(char c : s.toCharArray()) {
                st.set(c - 'a');
            }
            int n = st.cardinality();
            if(n < s.length()) continue;

            for(int i = dp.size() - 1; i>=0; i--) {
                BitSet curr = (BitSet) dp.get(i).clone();
                if(curr.intersects(st)) continue;
                ans = Math.max(ans, curr.cardinality() + n);
                curr.or(st);
                dp.add(curr);
            }
        }

        return ans;
    }
}