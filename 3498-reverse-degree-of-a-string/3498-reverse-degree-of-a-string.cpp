class Solution {
public:
    int reverseDegree(string s) {
        int ans=0;
        int i=1;
        for(char c:s){
            int r= 26-(c-'a');
            ans+=r*i;
            i++;
        }
        return ans;
    }
};