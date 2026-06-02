class Solution {
public:
    bool search(vector<int>& nums, int target) {
         int n = nums.size();
        int start = 0;
        int end = n - 1;
        bool ans = false;

        while (start <= end) {
            int mid = (start + end) / 2;
            if (nums[mid] == target) {
                ans = true;
            }
             if(nums[start]==nums[mid]&&nums[end]==nums[mid]){
                start++;
                end--;
                continue;
            }
            // checking if left part is sorted
            if (nums[start] <= nums[mid]) {
                if (target >= nums[start] && target <= nums[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
            // right part is sorted
            else {
                if (target <= nums[end] && target >= nums[mid]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }
        return ans;
    }
};