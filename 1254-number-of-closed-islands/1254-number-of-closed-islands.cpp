// class Solution {
//     bool travel(vector<vector<int>>& grid, vector<vector<bool>>& vis, int si,
//                 int sj, int m, int n) {
//         if (si < 0 || sj < 0 || si >= m || sj >= n) {
//             return false;
//         }
//         if (vis[si][sj] || grid[si][sj] == 1)
//             return true;
//         vis[si][sj] = true;
//         // if (grid[si][sj] == 1) {
//         //     return true;
//         // }

//         bool u = travel(grid, vis, si - 1, sj, m, n);
//         bool l = travel(grid, vis, si, sj - 1, m, n);
//         bool r = travel(grid, vis, si, sj + 1, m, n);
//         bool d = travel(grid, vis, si + 1, sj, m, n);
//         return (u && l && r && d);
//     }

// public:
//     int closedIsland(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         int ans = 0;
//         vector<vector<bool>> vis(m, vector<bool>(n, false));
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (!vis[i][j] && grid[i][j] == 0) {
//                     if (travel(grid, vis, i, j, m, n)) {
//                         ans++;
//                     }
//                 }
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:

    void dfs(vector<vector<int>>& grid,int i,int j,int m,int n){
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]==1) return;

        grid[i][j]=1;

        dfs(grid,i+1,j,m,n);
        dfs(grid,i-1,j,m,n);
        dfs(grid,i,j+1,m,n);
        dfs(grid,i,j-1,m,n);
    }

    int closedIsland(vector<vector<int>>& grid) {

        int m=grid.size();
        int n=grid[0].size();

        for(int i=0;i<m;i++){
            dfs(grid,i,0,m,n);
            dfs(grid,i,n-1,m,n);
        }

        for(int j=0;j<n;j++){
            dfs(grid,0,j,m,n);
            dfs(grid,m-1,j,m,n);
        }

        int ans=0;

        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                if(grid[i][j]==0){
                    ans++;
                    dfs(grid,i,j,m,n);
                }
            }
        }

        return ans;
    }
};