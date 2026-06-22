class Solution {
    void merge(vector<int>& nums,vector<int>& temp,int s,int m,int e){
        int p1=s;
        int p2=m+1;
        int fill=s;
        // vector<int> temp(e-s+1);
        while(p1<=m&&p2<=e){
            if(nums[p1]<=nums[p2]){
                temp[s++]=nums[p1++];
            }else{
                temp[s++]=nums[p2++];
            }
        }
        while(p1<=m){
            temp[s++]=nums[p1++];
        }
        while(p2<=e){
            temp[s++]=nums[p2++];
        }
        for(int i=fill;i<=e;i++){
            nums[i]=temp[i];
        }
    }
    void split(vector<int>& nums,vector<int>& temp,int s,int e){
        if(s>=e){
            return;
        }

        int mid=s+(e-s)/2;

        split(nums,temp,s,mid);
        split(nums,temp,mid+1,e);
        merge(nums,temp,s,mid,e);

    }
public:
    vector<int> sortArray(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        int n =nums.size();
        vector<int> temp(n);
        split(nums,temp,0,n-1);
        return nums;
        
    }
};