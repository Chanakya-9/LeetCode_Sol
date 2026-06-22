class Solution {
public:
    int binary(vector<vector<int>>& matrix, int mid) {
        int n = matrix.size();

        int row = n - 1;
        int col = 0;
        int cnt = 0;

        while (row >= 0 && col < n) {
            if (matrix[row][col] <= mid) {
                cnt += row + 1;
                col++;
            } else {
                row--;
            }
        }

        return cnt;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();

        int low = matrix[0][0];
        int high = matrix[n - 1][n - 1];

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (binary(matrix, mid) < k)
                low = mid + 1;
            else
                high = mid;
        }

        return low;
    }
};