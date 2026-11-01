class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end(),greater<int>());
        int ans=0;
        for(int i=1;i<n;i++){
            ans+=(nums[i]-nums[i-1])*i;
        }

        return ans*-1;

    }
};