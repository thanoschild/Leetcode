class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count[] = {0, 0};
        int n = students.size(), i;

        for(int choice : students) {
            count[choice]++;
        }

        for(i = 0; i<n && count[sandwiches[i]] > 0; i++) {
            count[sandwiches[i]]--;
        }

        return n - i;
    }
};