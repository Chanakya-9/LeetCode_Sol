class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        
        
        long long t = (long long)k1 + k2;
        
        
        vector<long long> count(100001, 0);
        long long sum_diff = 0;
        
        for (int i = 0; i < n; i++) {
            long long diff = abs(nums1[i] - nums2[i]);
            count[diff]++;
            sum_diff += diff;
        }
        
        
        if (sum_diff <= t) {
            return 0; 
        }
        
        
        for (int i = 100000; i > 0; i--) {
            if (count[i] > 0) {
                
                long long take = min(t, count[i]);
                
                
                count[i] -= take;
                count[i - 1] += take;
                
                
                t -= take;
                
                
                if (t == 0) {
                    break;
                }
            }
        }
        
        
        long long ans = 0;
        for (long long i = 1; i <= 100000; i++) {
            if (count[i] > 0) {
                ans += count[i] * i * i;
            }
        }
        
        return ans;
    }
};