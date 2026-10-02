// class Solution {
// public:
//     vector<string> generateParenthesis(int n) {
//         vector<vector<string>> dp(n + 1);
//         dp[1].push_back("()");
//         for (int i = 2; i <= n; i++) {
//             for (int j = 0; j < 3; j++) {
//                 for (int k = 0; k < dp[i - 1].size(); k++) {
//                     string s = dp[i - 1][k];
//                     string p = "";
//                     if (j == 0) {
//                         p = s + "()";
//                     }
//                     if (j == 1) {
//                         // string p="";
//                         p = "(" + s + ")";
//                     }
//                     if (j == 2) {
//                         // string p="";
//                         p = "()" + s;
//                     }
//                     dp[i].push_back(p);
//                 }
//             }
//             for (int j = 2; j <= i - 2; j++) {
//                 for (auto& a : dp[j]) {
//                     for (auto& b : dp[i - j]) {
//                         dp[i].push_back(a + b);
//                     }
//                 }
//             }
//         }
//         sort(dp[n].begin(), dp[n].end());
//         for (int i = 1; i < dp[n].size(); i++) {
//             if (dp[n][i] == dp[n][i - 1]) {
//                 dp[n].erase(dp[n].begin() + i);
//                 i--;
//             }
//         }
//         return dp[n];
//     }
// };

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> dp(n + 1);
        dp[0].push_back("");  // base case: empty string
        
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                for (auto& inner : dp[j]) {
                    for (auto& outer : dp[i - j - 1]) {
                        dp[i].push_back("(" + inner + ")" + outer);
                    }
                }
            }
        }
        return dp[n];
    }
};