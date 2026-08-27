class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26, 0);
        for (char c : s) cnt[c - 'a']++;

        for (int i = n - 1; i >= 0; i--) {
            vector<int> cur = cnt;
            bool ok = true;
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
                    string ans = target.substr(0, i);
                    ans += (char)('a' + c);

                    for (int ch = 0; ch < 26; ch++) {
                        while (cur[ch]-- > 0) {
                            ans += (char)('a' + ch);
                        }
                    }
                    return ans;
                }
            }
        }

        return "";
    }
};