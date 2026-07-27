class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int m1 = max(nums[0], nums[1]);
        int m2 = min(nums[0], nums[1]);

        int n=nums.size();

        for (int i=2;i<n;i++){
            int x=nums[i];
            if(x>m1){
                if(m1>m2){
                    m2 = m1 ;
                }
                m1=x;
            }else if(x>m2){
                m2=x;
            }
        }
        cout<<m1<<"  "<<m2;
        return (m1-1)*(m2-1);
    }
};