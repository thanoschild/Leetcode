class Pair<K, V> {
    private final K key;
    private final V value;

    public Pair(K key, V value) {
        this.key = key;
        this.value = value;
    }

    public K getKey() {
        return key;
    }

    public V getValue() {
        return value;
    }
}

class Solution {
    int[] count;
    
    void merge(List<Pair<Integer, Integer>> arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        List<Pair<Integer, Integer>> arr1 = new ArrayList<>(n1);
        List<Pair<Integer, Integer>> arr2 = new ArrayList<>(n2);

        for(int i = 0; i < n1; i++) {
            arr1.add(arr.get(left + i));
        }

        for(int i = 0; i < n2; i++) {
            arr2.add(arr.get(mid + 1 + i));
        }

        int p = 0, q = 0, r = left;
        while(p < n1 && q < n2) {
            if(arr1.get(p).getKey() <= arr2.get(q).getKey()) {
                count[arr1.get(p).getValue()] += q;
                arr.set(r, arr1.get(p));
                r++;
                p++;
            }
            else {
                arr.set(r, arr2.get(q));
                r++;
                q++;
            }
        }

        while(p < n1) {
            arr.set(r, arr1.get(p));
            count[arr1.get(p).getValue()] += q;
            r++;
            p++;
        }

        while(q < n2) {
            arr.set(r, arr2.get(q));
            r++;
            q++;
        }
    }

    void mergeSort(List<Pair<Integer, Integer>> arr, int left, int right) {
        if(left < right) {
            int mid = (right - left) / 2 + left;
            mergeSort(arr, left, mid);
            mergeSort(arr, mid + 1, right);
            merge(arr, left, mid, right);
        }
    }

    public List<Integer> countSmaller(int[] nums) {
        int n = nums.length;
        count = new int[n];

        List<Pair<Integer, Integer>> arr = new ArrayList<>();
        for(int i = 0; i < n; i++) {
            arr.add(new Pair<>(nums[i], i));
        }

        mergeSort(arr, 0, n - 1);

        List<Integer> result = new ArrayList<>();
        for(int value : count) {
            result.add(value);
        }
        return result;
    }
}