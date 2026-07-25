class Solution {
public:

    // Next Smaller Element (right side)
    vector<int> findNSE(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return ans;
    }

    // Previous Smaller or Equal Element (left side)
    vector<int> findPSEE(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return ans;
    }

    int sumSubarrayMins(vector<int> &arr) {
        int n = arr.size();
        vector<int> nse = findNSE(arr);
        vector<int> psee = findPSEE(arr);

        int mod = 1e9 + 7;
        long long sum = 0;

        for(int i = 0; i < n; i++) {
            long long left = i - psee[i];
            long long right = nse[i] - i;

            long long freq = left * right;
            long long val = (freq * arr[i]) % mod;

            sum = (sum + val) % mod;
        }

        return (int)sum;
    }
};