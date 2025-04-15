#define ll long long

class Fenwick {
public:
    vector<ll> tree;
    Fenwick(int n) {
        tree.assign(n + 1, 0);
    }

    void update(int k, int x) {
        k++;
        while (k < tree.size()) {
            tree[k] += x;
            k += (k & -k);
        }
    }

    ll query(int k) {
        ll total = 0;
        k++;
        while (k > 0) {
            total += tree[k];
            k -= (k & -k);
        }
        return total;
    }
};

class Solution {
public:
    ll goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> mpp(n);
        for (int i = 0; i < n; i++) mpp[nums1[i]] = i;

        Fenwick fw(n);
        ll result = 0;

        for (int i = 0; i < n; i++) {
            int idx = mpp[nums2[i]];
            ll left = fw.query(idx - 1); // elements less than idx
            ll right = (n - 1 - idx) - (fw.query(n - 1) - fw.query(idx)); // elements greater than idx
            result += left * right;
            fw.update(idx, 1);
        }

        return result;
    }
};
