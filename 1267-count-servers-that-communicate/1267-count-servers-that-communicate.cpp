class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int rowCount[250] = {0};
        int colCount[250] = {0};
        
        int r[62500];
        int c[62500];
        int totalServers = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    rowCount[i]++;
                    colCount[j]++;
                    r[totalServers] = i;
                    c[totalServers] = j;
                    totalServers++;
                }
            }
        }
        
        int count = 0;
        for (int i = 0; i < totalServers; ++i) {
            if (rowCount[r[i]] > 1 || colCount[c[i]] > 1) {
                count++;
            }
        }
        
        return count;
    }
};