class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int n =nums.size();

        int r=n-1;
        int l=0;

        if(n%2){
            n/=2;
            n++;
        }else{
            n/=2;
        }

        long long ans =0;

        
        while(n--){
            if(abs(nums[r])-abs(nums[l])>0){
                ans+=nums[r]*nums[r];
                r--;
            }else{
                ans+=nums[l]*nums[l];
                l++;

            }
        }

        while(l<=r){
            ans -= nums[l]*nums[l];
            l++;
        }

        return ans;


    }
};