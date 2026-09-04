class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n =nums.size();
        vector<int> fro (n,nums[0]);
        vector<int> back (n,nums[n-1]);
        for(int i=1;i<n;i++){
            fro[i]=max(nums[i],fro[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            back[i]=min(nums[i],back[i+1]);
        }

        for(int i=0;i<n;i++){
            int score=fro[i]-back[i];
            if(score<=k){
                return i;
            }
        }
        return -1;

    }
};