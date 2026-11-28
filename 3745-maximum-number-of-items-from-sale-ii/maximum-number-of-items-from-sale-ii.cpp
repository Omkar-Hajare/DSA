class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> freq(n + 1, 0);
        int minPrice = INT_MAX;

        for (auto& item : items) {
            freq[item[0]]++;
            minPrice = min(minPrice, item[1]);
        }

        vector<int> gain(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j += i) {
                gain[i] += freq[j];
            }
            gain[i]--;
        }

        sort(items.begin(), items.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });

        long long ans = 0;
        long long rem = budget;

        for (auto& item : items) {
            int factor = item[0];
            int price = item[1];

            if (price >= 2LL * minPrice)
                break;

            long long take = min((long long)gain[factor], rem / price);

            ans += take * 2;
            rem -= take * price;
        }

        ans += rem / minPrice;

        return (int)ans;
    }
};