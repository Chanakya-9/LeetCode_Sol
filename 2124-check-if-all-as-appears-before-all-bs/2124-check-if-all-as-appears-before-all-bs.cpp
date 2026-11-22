class Solution {
public:
    bool checkString(string s) {
        bool flag=false;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(flag && s[i]=='a'){
                return false;
            }
            if(s[i]=='b'){
                flag=true;
            }
        }
        return true;
    }
};