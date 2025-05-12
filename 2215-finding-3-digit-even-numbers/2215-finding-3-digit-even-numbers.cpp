class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> count(10, 0);
        for (auto it : digits)
            count[it]++;

        vector<int> ans;
        for (int i = 100; i < 999; i += 2) {
            vector<int> currCount(10, 0);
            int curr = i;

            while (curr) {
                currCount[curr % 10]++;
                curr /= 10;
            }

            bool flag = true;
            for (int j = 0; j < 10; j++) {
                if (currCount[j] > count[j]) {
                    flag = false;
                    break;
                }
            }

            if (flag)
                ans.push_back(i);
        }

        return ans;
    }
};