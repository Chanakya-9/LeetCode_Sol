class Solution {
    int sum(int x){
        if(!x){
            return 0;
        }
        int ans=0;
        ans+=x%10;
        return sum(x/10)+ans;
    }
public:
    int smallestIndex(vector<int>& nums) {
        
        int n = nums.size();
        for(int i =0;i<n;i++){
            if(sum(nums[i])==i){
                return i;
            }
        }
        return -1;
    }
};