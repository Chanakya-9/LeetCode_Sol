class Solution {
public:
    int maxProduct(int n) {
        string s = to_string(n);
        int max1 = 0;
        int max2 = 0;

        for (auto c : s) {
            int val = c - '0';
            if (max1 < val) {
                max2 = max1;
                max1 = val;

            } else {

                max2 = max(max2, val);
            }
        }
        return max1 * max2;
    }
};