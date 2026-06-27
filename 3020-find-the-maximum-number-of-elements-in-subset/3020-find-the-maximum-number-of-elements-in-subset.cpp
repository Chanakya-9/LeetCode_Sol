class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> cnt;
        for (int x : nums) cnt[x]++;

        int ans = 1;

        
        if (cnt.count(1)) {
            ans = max(ans, (cnt[1] & 1) ? cnt[1] : cnt[1] - 1);
        }

        for (auto &[x, f] : cnt) {
            if (x == 1) continue;

            long long cur = x;
            int len = 0;

            while (cnt[cur] >= 2) {
                long long nxt = cur * cur;

             
                if (!cnt.count(nxt)) {
                    len++;
                    break;
                }

                len += 2;
                cur = nxt;
            }

            if (cnt[cur] == 1)
                len++;

            ans = max(ans, len);
        }

        return ans;
    }
};