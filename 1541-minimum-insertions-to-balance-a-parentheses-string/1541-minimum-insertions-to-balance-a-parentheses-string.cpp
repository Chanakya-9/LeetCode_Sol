class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int o = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                if (o < 0) {
                    if (abs(o) % 2) {
                        ans++;
                        o--;
                    }
                    ans += (abs(o) / 2);
                    o=0;
                }
                if (o % 2) {
                    ans++;
                    o--;
                }
                o++;
                o++;
            } else {
                o--;
            }
        }
        if (o < 0) {
            if (abs(o) % 2) {
                ans++;
                o--;
            }
            ans += (abs(o) / 2);
        }else{
            ans += o;
        }

        return ans;
    }
};