class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n =nums.size();
        int mini=nums[0];
        int maxi=nums[n-1];
        unordered_set<int> st (nums.begin(),nums.end());
        vector<int> ans;
        for( int i= mini+1;i<maxi;i++){
            if(st.count(i)==0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};