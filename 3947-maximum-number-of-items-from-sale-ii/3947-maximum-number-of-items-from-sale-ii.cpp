class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int max_f = 0;
        long long min_price = 1e18;
        for (const auto& item : items) {
            max_f = max(max_f, item[0]);
            min_price = min(min_price, (long long)item[1]);
        }

        vector<int> freq(max_f + 1, 0);
        for (const auto& item : items) {
            freq[item[0]]++;
        }

        vector<int> mult_cnt(max_f + 1, 0);
        for (int f = 1; f <= max_f; f++) {
            if (freq[f] == 0) continue;
            for (int m = f; m <= max_f; m += f) {
                mult_cnt[f] += freq[m];
            }
        }

        vector<pair<int, int>> pairs;
        for (const auto& item : items) {
            int gain = mult_cnt[item[0]] - 1;
            if (gain > 0 && item[1] < 2LL * min_price) {
                pairs.push_back({item[1], gain});
            }
        }

        sort(pairs.begin(), pairs.end());

        long long rem = budget;
        long long ans = 0;
        for (const auto& [price, gain] : pairs) {
            long long take = min((long long)gain, rem / price);
            ans += 2 * take;
            rem -= take * price;
            if (rem < price) break;
        }

        ans += rem / min_price;
        return (int)ans;
    }
};