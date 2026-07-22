class Solution {
    bool travel(vector<vector<int>>& graph, vector<int>& vis, 
                int scr, int turn) {

        if(vis[scr]!=0){
            if(vis[scr]==turn){
                return true;
            }else{
                return false;
            }
        }
        

        vis[scr] = turn;
        for (auto v : graph[scr]) {
            if (!travel(graph, vis,v, -turn)) {
                return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> vis(n, 0);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (!travel(graph, vis, i, 1)) {
                    return false;
                }
            }
        }

        return true;
    }
};