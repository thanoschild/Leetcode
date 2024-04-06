class Solution {
    public List<List<Integer>> generate(int numRows) {
       List<List<Integer>> ans = new ArrayList<>();
       for(int i = 0; i<numRows; i++) {
           List<Integer> curr = new ArrayList<>(i+1);
           for(int j = 0; j<=i; j++) {
               if(j == 0 || j == i) curr.add(1);
               else curr.add(ans.get(i-1).get(j) + ans.get(i-1).get(j-1));
           }
           ans.add(curr);
       }

       return ans;
    }
}