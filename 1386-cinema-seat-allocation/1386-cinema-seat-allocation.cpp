class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> mp;
        for (auto& seat : reservedSeats) {
            int row = seat[0], col = seat[1];
            if (col >= 2 && col <= 9) {
                mp[row] |= (1 << (col - 1));
            }
        }

        int ans = (n - mp.size()) * 2;

        int left = 0b0000011110;
        int right = 0b0111100000;
        int mid = 0b0001111000;

        for (auto& [row, mask] : mp) {
            bool l = (mask & left) == 0;
            bool r = (mask & right) == 0;
            bool m = (mask & mid) == 0;

            if (l && r) {
                ans += 2;
            } else if (l || r || m) {
                ans += 1;
            }
        }

        return ans;
    }
};