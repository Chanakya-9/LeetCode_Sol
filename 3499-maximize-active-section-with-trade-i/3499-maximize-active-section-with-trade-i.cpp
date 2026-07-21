class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<int> zeros;
        int n = s.size();
        int curr = 0;
        bool con = false;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                curr++;
            } else {
                ans++;
                if (curr > 0) {
                    zeros.push_back(curr);
                }
                curr = 0;
            }
        }
        if(ans==n){
            return ans;
        }

        if (curr > 0) {
            zeros.push_back(curr);
        }

        int maxi=0;
        for(int i=1;i<zeros.size();i++){
            maxi=max(maxi,zeros[i]+zeros[i-1]);
        }
        return ans+maxi;


    }
};