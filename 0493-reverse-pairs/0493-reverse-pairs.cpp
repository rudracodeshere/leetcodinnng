class Solution {
public:
    int count = 0;
    void merge(vector<int>& arr, int left, int mid, int right) {
        vector<int> k(right - left + 1);
        int l = left;
        int r = mid + 1;
        int kind = 0;
        while (l <= mid && r <= right) {
            if (arr[l] > arr[r]) {
                k[kind++] = arr[r];
                r++;
            } else {
                k[kind++] = arr[l];
                l++;
            }
        }
        while (l <= mid) {
            k[kind++] = arr[l++];
        }
        while (r <= right) {
            k[kind++] = arr[r++];
        }

        for (int l = 0, s = left; l < k.size(); l++, s++) {
            arr[s] = k[l];
        }
    }

    void countPairs(vector<int>& nums, int l, int mid, int r) {
        int rt = mid + 1;
        for (int i = l; i <= mid; i++) {
            while (rt <= r && nums[i] > (long long) 2 * nums[rt])
                rt++;
            count = count + (rt - (mid + 1));
        }
    }

    void mergeSort(vector<int>& arr, int left, int right) {
        if (left >= right)
            return;

        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        countPairs(arr, left, mid, right);
        merge(arr, left, mid, right);
    }

    int reversePairs(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return count;
    }
};