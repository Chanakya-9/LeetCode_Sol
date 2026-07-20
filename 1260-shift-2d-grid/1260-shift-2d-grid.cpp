// class Solution {
// public:
//     vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
//         int n =grid.size();
//         int m =grid[0].size();
//         while(k--){
//             int store=grid[0][0];

//             for(int i=0;i<n;i++){
//                 for(int j=0;j<m;j++){
//                     if(i==0&&j==0){
//                         continue;
//                     }
//                     swap(store,grid[i][j]);
//                 }
//             }
//             swap(grid[0][0],store);
//         }

//         return grid;
        
//     }
// };

class Solution {
public:
    void reverse(vector<int> &v, int l, int r) {
        for (int i = l, j = r; i < j; i++, j--) {
            swap(v[i], v[j]);
        }
    }

    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> v;

        for (auto &row : grid) {
            for (auto &x : row) {
                v.push_back(x);
            }
        }

        k %= v.size();

        reverse(v, 0, v.size() - k - 1);
        reverse(v, v.size() - k, v.size() - 1);
        reverse(v, 0, v.size() - 1);

        int idx = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                grid[i][j] = v[idx++];
            }
        }

        return grid;
    }
};