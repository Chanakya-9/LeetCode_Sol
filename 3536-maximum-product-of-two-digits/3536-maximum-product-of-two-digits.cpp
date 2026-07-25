class Solution {
public:
    int maxProduct(int n) {

        if (n == 0) {
            return 0;
        }

        int mx1 = 0;
        int mx2 = 0;

        while (n) {

            int d = n % 10;
            n /= 10;

            if (d >= mx1) {
                mx2 = mx1;
                mx1 = d;
            } else if (d > mx2) {
                mx2 = d;
            }
        }

        return mx1 * mx2;
    }
};