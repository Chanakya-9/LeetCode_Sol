class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int n =grid.size();
        int m =grid[0].size();
        while(k--){
            int store=grid[0][0];

            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(i==0&&j==0){
                        continue;
                    }
                    swap(store,grid[i][j]);
                }
            }
            swap(grid[0][0],store);
        }

        return grid;
        
    }
};