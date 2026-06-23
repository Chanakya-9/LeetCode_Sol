class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int pg = 0;
        int ps = 0;
        int n = g.size();
        int m = s.size();

        int ans = 0;

        while (pg < n && ps < m) {
            if(s[ps]>=g[pg]){
                ans++;
                ps++;
                pg++;
            }else{
                ps++;
            }
        }
        return ans;
    }
};