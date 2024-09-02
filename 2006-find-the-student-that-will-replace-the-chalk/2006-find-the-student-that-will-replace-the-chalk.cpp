class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long total = 0;
        for(auto it : chalk) {
            total += it;
        }
        long long rem = k % total;
        for(int i = 0; i<chalk.size(); i++) {
            if(rem >= chalk[i]) rem -= chalk[i];
            else return i;
        }

        return -1;
    }
};