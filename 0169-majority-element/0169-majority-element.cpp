class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0, ele = 0;
        for(int it : nums) {
            if(count == 0) ele = it;
            if(ele == it) count++;
            else count--;
        }
        
        return ele;
    }
};