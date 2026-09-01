class Solution {
public:
    int minMoves(vector<string>& grid, int cap) {
        int m = grid.size(), n = grid[0].size();
        int sx = 0, sy = 0, k = 0;
        vector<vector<int>> id(m, vector<int>(n, -1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'S') {
                    sx = i;
                    sy = j;
                } else if (grid[i][j] == 'L') {
                    id[i][j] = k++;
                }
            }
        }

        int target = (1 << k) - 1;
        vector<vector<vector<int>>> best(m, vector<vector<int>>(n, vector<int>(1 << k, -1)));
        queue<tuple<int, int, int, int, int>> q;

        q.push({sx, sy, cap, 0, 0});
        best[sx][sy][0] = cap;

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [x, y, e, mask, dist] = q.front();
            q.pop();

            if (mask == target) return dist;
            if (e == 0) continue;

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] == 'X') continue;

                int ne = e - 1;
                int nmask = mask;

                if (grid[nx][ny] == 'L' && id[nx][ny] != -1) {
                    nmask |= (1 << id[nx][ny]);
                }
                if (grid[nx][ny] == 'R') {
                    ne = cap;
                }

                if (ne > best[nx][ny][nmask]) {
                    best[nx][ny][nmask] = ne;
                    q.push({nx, ny, ne, nmask, dist + 1});
                }
            }
        }

        return -1;
    }
};