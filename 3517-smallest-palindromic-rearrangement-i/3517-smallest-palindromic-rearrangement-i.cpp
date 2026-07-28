class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        vector<int> freq(26, 0);
        for (int i = 0; i < n; i++) {
            freq[s[i] - 'a'] ++;
           
        }

       

        int solo = -1;

        int p = 0;

        for (int i = 0; i < n / 2; i++) {
            while(p<26){
                if(freq[p]>1){
                    s[i]='a'+p;
                    s[n-1-i]='a'+p;
                    freq[p] -=2;
                    
                    break;
                }else if(freq[p]==1){
                    solo = p;
                }
                p++;
            }
        }
        if(solo!=-1){
            s[n/2]='a'+solo;
        }

        return s;

    }
};