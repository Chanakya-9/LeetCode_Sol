class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> cnt(10, 0);
        for (int d : digits) cnt[d]++;

        int ans = 0;
        for (int i = 100; i < 1000; i += 2) {
            int d1 = i / 100;
            int d2 = (i / 10) % 10;
            int d3 = i % 10;

            vector<int> cur(10, 0);
            cur[d1]++;
            cur[d2]++;
            cur[d3]++;

            bool ok = true;
            for (int d = 0; d < 10; d++) {
                if (cur[d] > cnt[d]) {
                    ok = false;
                    break;
                }
            }

            if (ok) ans++;
        }

        return ans;
    }
};