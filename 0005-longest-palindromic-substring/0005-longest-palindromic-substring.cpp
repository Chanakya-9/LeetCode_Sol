class Solution {
    int st=0;
    int len=1;
    int n ;


    void expand(string &s,int l,int r){
        while(l>=0 &&r<n&&s[l]==s[r]){
            l--;
            r++;
        }
        int curr=r-l-1;
        if(curr>len){
            len=curr;
            st=l+1;
        }
    }
public:
    string longestPalindrome(string s) {
        n=s.size();

        for(int i=0;i<n;i++){
            expand(s,i,i);
            expand(s,i,i+1);
        }
        string ans="";
        while(len--){
            ans.push_back(s[st++]);
        }
        return ans;
    }
};