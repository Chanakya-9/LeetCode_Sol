class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> cnt(10, 0);
        for (int d : digits) cnt[d]++;

        int ans = 0;
        for (int i = 100; i < 1000; i += 2) {
            int d1 = i / 100, d2 = (i / 10) % 10, d3 = i % 10;
            cnt[d1]--; cnt[d2]--; cnt[d3]--;
            if (cnt[d1] >= 0 && cnt[d2] >= 0 && cnt[d3] >= 0) ans++;
            cnt[d1]++; cnt[d2]++; cnt[d3]++;
        }

        return ans;
    }
};