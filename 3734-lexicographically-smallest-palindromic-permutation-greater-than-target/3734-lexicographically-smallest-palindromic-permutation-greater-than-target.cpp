class Solution {
    string build(const string& pref, int n, int m, int mid_idx) {
        string res = pref;
        if (n % 2 != 0) res += (char)('a' + mid_idx);
        for (int i = m - 1; i >= 0; i--) res += pref[i];
        return res;
    }

public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size(), m = n / 2;
        vector<int> cnt(26, 0);
        for (char c : s) cnt[c - 'a']++;

        int odd = 0, mid_idx = -1;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2 != 0) {
                odd++;
                mid_idx = i;
            }
        }
        if (odd > 1) return "";

        vector<int> half(26, 0);
        for (int i = 0; i < 26; i++) half[i] = cnt[i] / 2;

        vector<int> cur = half;
        bool ok = true;
        for (int i = 0; i < m; i++) {
            if (--cur[target[i] - 'a'] < 0) {
                ok = false;
                break;
            }
        }

        if (ok) {
            string cand = build(target.substr(0, m), n, m, mid_idx);
            if (cand > target) return cand;
        }

        for (int i = m - 1; i >= 0; i--) {
            cur = half;
            ok = true;
            for (int j = 0; j < i; j++) {
                if (--cur[target[j] - 'a'] < 0) {
                    ok = false;
                    break;
                }
            }
            if (!ok) continue;

            for (int c = target[i] - 'a' + 1; c < 26; c++) {
                if (cur[c] > 0) {
                    cur[c]--;
                    string pref = target.substr(0, i);
                    pref += (char)('a' + c);

                    for (int ch = 0; ch < 26; ch++) {
                        while (cur[ch]-- > 0) {
                            pref += (char)('a' + ch);
                        }
                    }
                    return build(pref, n, m, mid_idx);
                }
            }
        }

        return "";
    }
};