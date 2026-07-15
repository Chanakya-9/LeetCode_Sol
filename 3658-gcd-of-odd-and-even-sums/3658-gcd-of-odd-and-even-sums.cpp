class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int odd = n*n;
        int even = n*(n-1);

        for(int i = min(odd,even);i>0;i--){
            if(!(odd%i)&&!(even%i)){
                return i;
            }
        }
        return 1;
    }
};