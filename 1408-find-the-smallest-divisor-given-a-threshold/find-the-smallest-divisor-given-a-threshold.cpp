class Solution {
public:
    bool possible(vector<int>& nums, int num, int t) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            ans += ceil((double)nums[i] / num);
        }
        return ans <= t;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi = *max_element(nums.begin(), nums.end());

        int start = 1;
        int end = maxi;
        int result;

        while (start <= end) {
            int mid = (start + end) / 2;

            if (possible(nums, mid, threshold) == true) {
                result = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return result;
    }
};