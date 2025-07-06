class FindSumPairs {
public:
    vector<int> nums1, nums2;
    map<int,int> mp;
    FindSumPairs(vector<int>& arr1, vector<int>& arr2) {
        nums1 = arr1;
        nums2 = arr2;
        for(auto it : nums2) mp[it]++;
        sort(nums1.begin(), nums1.end());
    }
    
    void add(int index, int val) {
        mp[nums2[index]]--;
        if(mp[nums2[index]] == 0) mp.erase(nums2[index]);
        nums2[index] += val;
        mp[nums2[index]]++;
    }
    
    int count(int tot) {
        int ans = 0;
        for(auto it : nums1) {
            if(it > tot) break;

            int val = tot - it;
            ans += mp[val];
        }

        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */