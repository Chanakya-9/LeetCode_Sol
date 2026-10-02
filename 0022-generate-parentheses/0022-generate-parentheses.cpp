class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> dp(n+1);
        dp[0]={""};
        for(int k=0;k<=n;k++){
            for(int i=0;i<k;i++){
                for(auto in:dp[i]){
                    for(auto out:dp[k-i-1]){
                        dp[k].push_back('('+in+')'+out);
                    }
                }
            }
        }
        return dp[n];
    }
};