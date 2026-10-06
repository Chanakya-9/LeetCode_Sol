class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0;
        int o = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                o++;
            } else {
                o--;
                if (o < 0) {
                    ans++;
                    o = 0;
                }
            }
        }
        if (o > 0) {
            ans += abs(o);
        }
        return ans;
    }
};