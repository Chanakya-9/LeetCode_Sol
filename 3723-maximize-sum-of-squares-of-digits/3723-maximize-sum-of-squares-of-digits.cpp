class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (9 * num < sum) {
            return "";
        }
        string ans = "";
        int nine = sum / 9;
        int left = sum % 9;

        while (nine--) {
            ans.push_back('9');
            num--;
        }

        if (left) {
            ans.push_back('0' + left);
            num--;
        }

        while (num--) {
            ans.push_back('0');
        }

        return ans;
    }
};