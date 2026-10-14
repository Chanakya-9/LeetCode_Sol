class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (9 * num < sum) {
            return "";
        }
        string ans = "";
        int n = sum / 9;
        int left = sum % 9;

        ans.append(n, '9'); num -= n;

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