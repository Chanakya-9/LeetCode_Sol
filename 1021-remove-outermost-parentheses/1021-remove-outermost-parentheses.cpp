class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.size();
        int o=0;
        string ans="";
        bool skip=true;

        for(int i=0;i<n;i++){
            if(s[i]=='('){
                o++;
            }else{
                o--;
            }
            if(o==0||skip){
                skip=false;
                if(o==0){
                    skip=true;
                }
                continue;
            }
            ans.push_back(s[i]);
        }

        return ans;
        
    }
};