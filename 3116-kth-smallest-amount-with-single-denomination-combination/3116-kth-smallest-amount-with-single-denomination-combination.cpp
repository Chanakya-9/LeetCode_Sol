class Solution {
    long long gcd(long long a, long long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    long long lcm(long long a, long long b) {
        if (a == 0 || b == 0) return 0;
        return (a / gcd(a, b)) * b;
    }

    long long count(long long m, vector<int>& coins) {
        int k = coins.size();
        long long cnt = 0;

        for (int mask = 1; mask < (1 << k); mask++) {
            long long cur_lcm = 1;
            int bits = 0;
            bool overflow = false;

            for (int i = 0; i < k; i++) {
                if (mask & (1 << i)) {
                    bits++;
                    cur_lcm = lcm(cur_lcm, (long long)coins[i]);
                    if (cur_lcm > m) {
                        overflow = true;
                        break;
                    }
                }
            }

            if (!overflow) {
                if (bits % 2 == 1) cnt += m / cur_lcm;
                else cnt -= m / cur_lcm;
            }
        }
        return cnt;
    }

public:
    long long findKthSmallest(vector<int>& coins, int k) {
        long long l = 1, r = 1LL * *min_element(coins.begin(), coins.end()) * k;
        long long ans = r;

        while (l <= r) {
            long long mid = l + (r - l) / 2;
            if (count(mid, coins) >= k) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};