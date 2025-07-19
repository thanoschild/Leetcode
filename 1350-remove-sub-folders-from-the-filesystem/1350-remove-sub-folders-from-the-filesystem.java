class Solution {
    public List<String> removeSubfolders(String[] folder) {
        Arrays.sort(folder, Comparator.comparing(s -> s.length()));
        HashSet<String> st = new HashSet<>();

        for(String s : folder) {
            StringBuilder curr = new StringBuilder();
            boolean flag = true;

            for(char c : s.toCharArray()) {
                if(c == '/' && curr.length() > 0) {
                    if(st.contains(curr.toString())) {
                        flag = false;
                        break;
                    }
                }
                curr.append(c);
            }

            if(flag) st.add(s);
        }

        List<String> ans = new ArrayList<>();
        for(String s : st) {
            ans.add(s);
        }

        return ans;
    }
}