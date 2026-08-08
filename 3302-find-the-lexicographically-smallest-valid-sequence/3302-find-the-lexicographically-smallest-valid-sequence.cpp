class Solution {
public:
    vector<int> validSequence(string word1, string word2) {

        int n = word1.size();
        int m = word2.size();

        vector<int> suf(n + 1, 0);

        int j = m - 1;

        for (int i = n - 1; i >= 0; i--) {
            suf[i] = suf[i + 1];

            if (j >= 0 && word1[i] == word2[j]) {
                suf[i]++;
                j--;
            }
        }

        vector<int> ans;

        int p = 0;
        bool used = false;

        for (int i = 0; i < n && p < m; i++) {

            if (word1[i] == word2[p]) {
                ans.push_back(i);
                p++;
            }
            else if (!used) {

                int rem = m - p - 1;

                if (suf[i + 1] >= rem) {
                    ans.push_back(i);
                    p++;
                    used = true;
                }
            }
        }

        if (p != m) {
            return {};
        }

        return ans;
    }
};