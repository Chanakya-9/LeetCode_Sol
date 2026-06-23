class Solution {
    vector<vector<int>> ans;

    void travel(int i,int n,vector<int>& nums,vector<int>& curr){
        if(i==n){
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);
        travel(i+1,n,nums,curr);
        curr.pop_back();
        travel(i+1,n,nums,curr);

    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n =nums.size();
        vector<int> curr;

        travel(0,n,nums,curr);

        return ans;
        
    }
};