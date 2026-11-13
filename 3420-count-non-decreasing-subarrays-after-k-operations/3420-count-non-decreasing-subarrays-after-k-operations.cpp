class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long ans = 0;
        deque<pair<long long, int>> dq; 
        long long current_cost = 0;
        int j = n - 1;

        for (int i = n - 1; i >= 0; i--) {
            long long val = nums[i];
            int count = 1;
            
            while (!dq.empty() && dq.front().first <= val) {
                current_cost += 1LL * dq.front().second * (val - dq.front().first);
                count += dq.front().second;
                dq.pop_front();
            }
            dq.push_front({val, count});
            
            while (current_cost > k) {
                current_cost -= (dq.back().first - nums[j]);
                dq.back().second--;
                if (dq.back().second == 0) {
                    dq.pop_back();
                }
                j--;
            }
            
            ans += (j - i + 1);
        }
        
        return ans;
    }
};