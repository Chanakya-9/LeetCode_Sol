class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dis) {

        vector<vector<pair<int,int>>> gp(n);

        for(auto &e:edges){
            gp[e[0]].push_back({e[1],e[2]});
            gp[e[1]].push_back({e[0],e[2]});
        }

        int ans = -1;
        int mini = INT_MAX;

        for(int i=0;i<n;i++){

            vector<int> dist(n,INT_MAX);
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

            dist[i]=0;
            pq.push({0,i});

            while(!pq.empty()){
                auto cur=pq.top();
                pq.pop();

                int d=cur.first;
                int u=cur.second;

                if(d>dist[u]) continue;

                for(auto nei:gp[u]){
                    int v=nei.first;
                    int w=nei.second;

                    if(dist[v]>d+w){
                        dist[v]=d+w;
                        pq.push({dist[v],v});
                    }
                }
            }

            int cnt=0;
            for(int j=0;j<n;j++){
                if(dist[j]<=dis) cnt++;
            }

            if(cnt<=mini){
                mini=cnt;
                ans=i;
            }
        }

        return ans;
    }
};