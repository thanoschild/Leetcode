class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int i = 0, j = people.size() - 1, ans = 0;

        while(i <= j) {
            int sum = people[i] + people[j];
            if(sum <= limit) {
                ans++, i++, j--;
            }
            else {
                ans++, j--;
            }
        }

        return ans;
    }
};