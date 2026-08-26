class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        string ans = "";
        int l = 0, cnt = 0;

        for (int r = 0; r < n; r++) {
            if (s[r] == '1') cnt++;

            while (cnt == k) {
                while (s[l] == '0') l++;

                string cur = s.substr(l, r - l + 1);
                if (ans == "" || cur.size() < ans.size() || (cur.size() == ans.size() && cur < ans)) {
                    ans = cur;
                }

                if (s[l] == '1') cnt--;
                l++;
            }
        }

        return ans;
    }
};