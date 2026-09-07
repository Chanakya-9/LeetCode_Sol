class Solution {
public:
    int distinctSubseqII(string s) {
        long long mod = 1e9 + 7;
        vector<long long> last(26, 0);
        long long total = 0;

        for (char c : s) {
            int idx = c - 'a';
            long long cur = (total + 1) % mod;
            long long diff = (cur - last[idx] + mod) % mod;
            total = (total + diff) % mod;
            last[idx] = cur;
        }

        return total;
    }
};