class Solution {
    int n; 
    int m; 
    vector<vector<char>> mat;
    vector<vector<vector<int>>> dp;
    bool travel(int si,int sj,int o){
        if(si>=m||sj>=n){
            return false;
        }
        if(mat[si][sj]=='('){
            o++;
        }else{
            o--;
        }
        if(o<0){
            return false;
        }
         if (dp[si][sj][o] != -1)
            return dp[si][sj][o];

        if(si==m-1&&sj==n-1){
            return dp[si][sj][o] = (o==0);

        }
        return dp[si][sj][o] =
    travel(si+1,sj,o) || travel(si,sj+1,o);
    }
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        m=grid.size();
        n=grid[0].size();
        mat=grid;
        dp.resize(m, vector<vector<int>>(n, vector<int>(m + n + 1, -1)));

        return travel(0,0,0);
    }
};