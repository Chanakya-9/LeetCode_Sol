class Solution {
public:
    int minimumRefill(vector<int>& plants, int capa, int capb) {

        int ans = 0;
        int n = plants.size();
        int pa = 0;
        int pb = n - 1;
        int la = capa;
        int lb = capb;

        while (pa < pb) {
            if (la >= plants[pa]) {
                la -= plants[pa];
                pa++;
            } else {
                ans++;
                la = capa;
                la -= plants[pa];
                pa++;
            }
            if (lb >= plants[pb]) {
                lb -= plants[pb];
                pb--;
            } else {
                ans++;
                lb = capb;
                lb -= plants[pb];
                pb--;
            }
        }
        if(pa==pb){
            la=max(la,lb);
            if(la<plants[pa]){
                ans++;
            }
        }

        return ans;
    }
};