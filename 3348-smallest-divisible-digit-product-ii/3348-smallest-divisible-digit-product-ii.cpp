class Solution {
public:
    string smallestNumber(string num, long long t) {
        long long temp = t;
        int R2 = 0, R3 = 0, R5 = 0, R7 = 0;
        while (temp % 2 == 0) { R2++; temp /= 2; }
        while (temp % 3 == 0) { R3++; temp /= 3; }
        while (temp % 5 == 0) { R5++; temp /= 5; }
        while (temp % 7 == 0) { R7++; temp /= 7; }
        if (temp > 1) return "-1";

        vector<vector<int>> dp(60, vector<int>(60, 1e9));
        dp[0][0] = 0;
        for (int i = 0; i < 60; ++i) {
            for (int j = 0; j < 60; ++j) {
                if (i == 0 && j == 0) continue;
                int ans = 1e9;
                ans = min(ans, 1 + dp[max(0, i - 1)][j]);
                ans = min(ans, 1 + dp[i][max(0, j - 1)]);
                ans = min(ans, 1 + dp[max(0, i - 2)][j]);
                ans = min(ans, 1 + dp[max(0, i - 1)][max(0, j - 1)]);
                ans = min(ans, 1 + dp[max(0, i - 3)][j]);
                ans = min(ans, 1 + dp[i][max(0, j - 2)]);
                dp[i][j] = ans;
            }
        }

        auto get_f = [](int d) {
            int f2 = 0, f3 = 0, f5 = 0, f7 = 0;
            if (d == 0) return make_tuple(0, 0, 0, 0);
            while (d % 2 == 0) { f2++; d /= 2; }
            while (d % 3 == 0) { f3++; d /= 3; }
            while (d % 5 == 0) { f5++; d /= 5; }
            while (d % 7 == 0) { f7++; d /= 7; }
            return make_tuple(f2, f3, f5, f7);
        };

        int n = num.size();
        int z_idx = num.find('0');
        if (z_idx == string::npos) z_idx = n;

        vector<int> p2(n + 1, 0), p3(n + 1, 0), p5(n + 1, 0), p7(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            if (num[i] == '0') break;
            auto [f2, f3, f5, f7] = get_f(num[i] - '0');
            p2[i + 1] = p2[i] + f2;
            p3[i + 1] = p3[i] + f3;
            p5[i + 1] = p5[i] + f5;
            p7[i + 1] = p7[i] + f7;
        }

        if (z_idx == n && p2[n] >= R2 && p3[n] >= R3 && p5[n] >= R5 && p7[n] >= R7) {
            return num;
        }

        for (int i = min(n - 1, z_idx); i >= 0; --i) {
            for (int d = num[i] - '0' + 1; d <= 9; ++d) {
                auto [f2, f3, f5, f7] = get_f(d);
                int rem2 = max(0, R2 - p2[i] - f2);
                int rem3 = max(0, R3 - p3[i] - f3);
                int rem5 = max(0, R5 - p5[i] - f5);
                int rem7 = max(0, R7 - p7[i] - f7);

                if (dp[rem2][rem3] + rem5 + rem7 <= n - 1 - i) {
                    string ans = num.substr(0, i) + (char)('0' + d);
                    int cur2 = p2[i] + f2, cur3 = p3[i] + f3;
                    int cur5 = p5[i] + f5, cur7 = p7[i] + f7;

                    for (int j = i + 1; j < n; ++j) {
                        for (int c = 1; c <= 9; ++c) {
                            auto [cf2, cf3, cf5, cf7] = get_f(c);
                            int tr2 = max(0, R2 - cur2 - cf2);
                            int tr3 = max(0, R3 - cur3 - cf3);
                            int tr5 = max(0, R5 - cur5 - cf5);
                            int tr7 = max(0, R7 - cur7 - cf7);
                            if (dp[tr2][tr3] + tr5 + tr7 <= n - 1 - j) {
                                ans += (char)('0' + c);
                                cur2 += cf2; cur3 += cf3;
                                cur5 += cf5; cur7 += cf7;
                                break;
                            }
                        }
                    }
                    return ans;
                }
            }
        }

        int L = max(n + 1, dp[R2][R3] + R5 + R7);
        string ans = "";
        int cur2 = 0, cur3 = 0, cur5 = 0, cur7 = 0;
        for (int j = 0; j < L; ++j) {
            for (int c = 1; c <= 9; ++c) {
                auto [cf2, cf3, cf5, cf7] = get_f(c);
                int tr2 = max(0, R2 - cur2 - cf2);
                int tr3 = max(0, R3 - cur3 - cf3);
                int tr5 = max(0, R5 - cur5 - cf5);
                int tr7 = max(0, R7 - cur7 - cf7);
                if (dp[tr2][tr3] + tr5 + tr7 <= L - 1 - j) {
                    ans += (char)('0' + c);
                    cur2 += cf2; cur3 += cf3;
                    cur5 += cf5; cur7 += cf7;
                    break;
                }
            }
        }
        return ans;
    }
};