class Solution {
public:
    int convert(vector<int> &mp, int num) {
        if (num < 10) {
            return mp[num];
        }
        
        int new_num = 0;
        int base = 1;
        while (num) {
            int new_digit = mp[num % 10];
            new_num += new_digit * base;
            num /= 10;
            base *= 10;
        }
        return new_num;
    }
    
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        sort(nums.begin(), nums.end(), [&mapping, this](const int &a, const int &b) {
            int first = this->convert(mapping, a);
            int second = this->convert(mapping, b);
            return first < second;
        });

        return nums;
    }
};