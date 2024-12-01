class Solution {
    public boolean checkIfExist(int[] arr) {
        HashSet<Integer> st = new HashSet<Integer>();
        for(int it : arr) {
            if(st.contains(it*2)) return true;
            if(it%2 == 0 && st.contains(it/2)) return true;
            st.add(it);
        }

        return false;
    }
}