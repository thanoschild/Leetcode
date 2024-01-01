class Solution {
    private boolean check(int mid, List<Integer> a) {
        int count = 0;
        for(int x : a) {
            count += Math.max(0, x - mid + 1);
        }

        return count >= 3;
    }

    public int maximumLength(String s) {
        int n = s.length();
        List<List<Integer>> freq = new ArrayList<>(26);
        for (int i = 0; i < 26; i++) {
            freq.add(new ArrayList<>());
        }

        int count = 1;
        for(int i = 1; i<n; i++) {
            if(s.charAt(i) != s.charAt(i-1)) {
                freq.get(s.charAt(i-1) - 'a').add(count);
                count = 1;
            }
            else {
                count++;
            }
        }
        freq.get(s.charAt(n-1) - 'a').add(count);

        int ans = -1;
        for(int i = 0; i<26; i++) {
            if(freq.get(i).isEmpty()) continue;
            int m = freq.get(i).size();
            Collections.sort(freq.get(i));
            int start = 1, end = freq.get(i).get(m - 1);

            while(start <= end) {
                int mid = start + (end - start)/2;
                if(check(mid, freq.get(i))) {
                    ans = Math.max(ans, mid);
                    start = mid + 1;
                }
                else {
                    end = mid - 1;
                }
            }
        }

        return ans;
    }
}