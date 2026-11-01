// class Solution {
// public:
//     int minMoves(vector<int>& nums) {
//         int n = nums.size();
//         sort(nums.begin(),nums.end(),greater<int>());
//         int ans=0;
//         for(int i=1;i<n;i++){
//             ans+=(nums[i]-nums[i-1])*i;
//         }

//         return ans*-1;

//     }
// };


class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int mini = INT_MAX;
        
        for(int i = 0; i<n; i++) {
            mini = min(mini, nums[i]);
        }

        for(int i = 0; i<n; i++) {
            ans += abs(nums[i] - mini);
        }

        return ans;
    }
};