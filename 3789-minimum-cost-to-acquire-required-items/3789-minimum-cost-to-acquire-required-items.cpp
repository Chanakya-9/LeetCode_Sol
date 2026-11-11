class Solution {
public:
    long long minimumCost(int c1, int c2, int both, int n1, int n2) {
        long long ans;

        if (1LL * both > 1LL * c1 + c2) {
            ans = 1LL * n1 * c1 + 1LL * n2 * c2;
            return ans;
        }

        int mini = min(n1, n2);

        ans = 1LL * mini * both;

        n1 -= mini;
        n2 -= mini;

        ans += 1LL * n1 * min(c1, both);
        ans += 1LL * n2 * min(c2, both);

        return ans;
    }
};