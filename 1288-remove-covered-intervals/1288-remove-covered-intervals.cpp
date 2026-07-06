class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& in) {
        sort(in.begin(), in.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
             });

        int c = 0, re = 0;
        for (auto& i : in) {
            if (i[1] > re) {
                c++;
                re = i[1];
            }
        }
        return c;
    }
};