class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        if (n <= 1)
            return 0;
        if (is_sorted(s.begin(), s.end()))
            return 0;
        if (n == 2)
            return -1;

        int mn = s[0], mx = s[0];
        int mn_cnt = 0, mx_cnt = 0;

        for (char c : s) {
            if (c < mn) {
                mn = c;
                mn_cnt = 1;
            } else if (c == mn) {
                mn_cnt++;
            }

            if (c > mx) {
                mx = c;
                mx_cnt = 1;
            } else if (c == mx) {
                mx_cnt++;
            }
        }

        if (s[n - 1] == mx || s[0] == mn) {
            return 1;
        }

        if (s[0] == mx && s[n - 1] == mn && mn_cnt == 1 && mx_cnt == 1) {
            return 3;
        }

        return 2;
    }
};