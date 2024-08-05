class Solution {
    public String kthDistinct(String[] arr, int k) {
        HashMap<String,Integer> mp = new HashMap<>();
        for(String s : arr) {
            mp.put(s, mp.getOrDefault(s, 0) + 1);
        }

        for(String s : arr) {
            if(mp.get(s) == 1 && --k == 0) return s;
        }

        return "";
    }
}