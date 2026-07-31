class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26,0);

        for(auto c:word){
            freq[c-'a']++;
        }
        sort(freq.begin(),freq.end(),greater<int>());

        int ans=0;
        int press=1;
        int key=1;
        for(int i=0;i<26;i++){
            if(key==9){
                key=1;
                press++;
            }
            ans+=(press*freq[i]);
            key++;
        }

        return ans;

        
    }
};