class Solution {
    public int countStudents(int[] students, int[] sandwiches) {
        int[] count = {0, 0};
        int n = students.length, i;

        for(int val : students) {
            count[val]++;
        }

        for(i = 0; i<n && count[sandwiches[i]] > 0; i++) {
            count[sandwiches[i]]--;
        }

        return n - i;
    }
}