class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n = nums1.size(), m = nums2.size(), i = 0, j = 0;
        vector<vector<int>> ans;

        while(i < n && j < m) {
           int id1 = nums1[i][0], val1 = nums1[i][1];
           int id2 = nums2[j][0], val2 = nums2[j][1];
           
           if(id1 < id2) {
                ans.push_back({id1, val1});
                i++;
           } else if(id1 > id2) {
                ans.push_back({id2, val2});
                j++;
           } else {
                ans.push_back({id1, val1 + val2});
                i++, j++;
           }
        }

        while(i < n) {
            ans.push_back(nums1[i]);
            i++;
        }

        while(j < m) {
            ans.push_back(nums2[j]);
            j++;
        }

        return ans;
    }
};