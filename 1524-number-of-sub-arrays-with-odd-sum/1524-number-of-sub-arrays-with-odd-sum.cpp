class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int odd_count = 0;
        int even_count = 1;
        int ans = 0;
        int sum = 0;
        const int MOD = 1e9 + 7;
        
        for (int x : arr) {
            sum += x;
            if (sum % 2 == 0) {
                ans = (ans + odd_count) % MOD;
                even_count++;
            } else {
                ans = (ans + even_count) % MOD;
                odd_count++;
            }
        }
        
        return ans;
    }
};