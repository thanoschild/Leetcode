class Solution {
public:
    vector<int> count;

    void merge(vector<pair<int,int>> &arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<pair<int, int>> arr1(n1);
        vector<pair<int, int>> arr2(n2);
        
        for(int i = 0; i<n1; i++) {
            arr1[i] = arr[left + i];
        } 

        for(int i = 0; i<n2; i++) {
            arr2[i] = arr[mid + 1 + i];
        }

        int p = 0, q = 0, r = left;
        while(p < n1 && q < n2) {
            if(arr1[p].first <= arr2[q].first) {
                count[arr1[p].second] += q;
                arr[r] = arr1[p];
                r++, p++;
            }
            else {
                arr[r] = arr2[q];
                r++, q++;
            }
        }

        while(p < n1) {
            arr[r] = arr1[p];
            count[arr1[p].second] += q;
            r++, p++;
        }

        while(q < n2) {
            arr[r] = arr2[q];
            r++, q++;
        }
    }

    void mergeSort(vector<pair<int, int>> &arr, int left, int right) {
        if(left < right) {
            int mid = (right - left)/2 + left;
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        count.resize(n, 0);

        vector<pair<int, int>> arr;
        for(int i = 0; i<n; i++) {
            arr.push_back({nums[i], i});
        }

        mergeSort(arr, 0, n - 1);
        return count;
    }
};