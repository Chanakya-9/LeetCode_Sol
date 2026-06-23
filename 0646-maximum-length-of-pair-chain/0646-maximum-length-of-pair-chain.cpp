class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(),
             [](auto& a, auto& b) { return a[1] < b[1]; });

        int ans = 0;
        int end = INT_MIN;

        for (auto& p : pairs) {
            if (p[0] > end) {
                ans++;
                end = p[1];
            }
        }
        return ans;
    }
};