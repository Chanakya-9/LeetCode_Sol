class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> l(26, INT_MAX), r(26, -1);
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            l[c] = min(l[c], i);
            r[c] = max(r[c], i);
        }

        vector<pair<int, int>> intervals;
        for (int i = 0; i < 26; i++) {
            if (l[i] == INT_MAX) continue;
            int right = r[i];
            bool ok = true;

            for (int j = l[i]; j <= right; j++) {
                int c = s[j] - 'a';
                if (l[c] < l[i]) {
                    ok = false;
                    break;
                }
                right = max(right, r[c]);
            }

            if (ok) {
                intervals.push_back({right, l[i]});
            }
        }

        sort(intervals.begin(), intervals.end());

        vector<string> ans;
        int last = -1;
        for (auto [right, left] : intervals) {
            if (left > last) {
                ans.push_back(s.substr(left, right - left + 1));
                last = right;
            }
        }

        return ans;
    }
};