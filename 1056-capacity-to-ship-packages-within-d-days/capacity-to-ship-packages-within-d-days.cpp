class Solution {
public:
    bool possible(vector<int>& arr, int weight, int d) {
    int days = 1;
    int sum = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (sum + arr[i] > weight) {
            days++;
            sum = arr[i];
        } else {
            sum += arr[i];
        }
    }

    return days <= d;
}

    int shipWithinDays(vector<int>& weights, int days) {
        int maxi = *max_element(weights.begin(), weights.end());

        int start = maxi;
        int end = accumulate(weights.begin(), weights.end(), 0);
    

        while (start <= end) {
            int mid = (start + end) / 2;


            if (possible(weights, mid, days) == true) {
             
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return start;
    }
};