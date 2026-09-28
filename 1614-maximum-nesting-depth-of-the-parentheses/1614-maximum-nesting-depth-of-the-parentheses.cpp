class Solution {
public:
    int maxDepth(string s) {
        int o=0;
        int ans=0;
        for(auto c:s){
            if(c=='('){
                o++;
            }else if(c==')'){
                ans=max(ans,o);
                o--;
            }
        }
        return ans;
    }
};