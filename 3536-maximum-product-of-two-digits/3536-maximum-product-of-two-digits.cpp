class Solution {
public:
    int maxProduct(int n) {
        string s = to_string(n);

        vector<int> freq(10, 0);

        for (auto c : s) {
            freq[c - '0']++;
        }

        int ans = 1;
        int cnt = 2;

        for (int i = 9; i >= 0 && cnt; i--) {
            while (freq[i] && cnt) {
                ans *= i;
                freq[i]--;
                cnt--;
            }
        }

        return ans;
    }
};