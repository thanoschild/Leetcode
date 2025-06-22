class Solution {
    public String[] divideString(String s, int k, char fill) {
        List<String> result = new ArrayList<>();
        String str = "";
        int n = s.length();

        for(int i = 0; i<n; i++) {
            char c = s.charAt(i);
            str += c;
            if(str.length() == k) {
                result.add(str);
                str = "";
            }
        }

        if(str.length() > 0) {
            while(str.length() < k) str += fill;
            result.add(str);
        }

        String[] ans = new String[result.size()];
        for(int i = 0; i<result.size(); i++) ans[i] = result.get(i);

        return ans;
    }
}