class Solution {
public:
    bool checkDivisibility(int n) {
        int pro=1;
        int sum=0;
        int num=n;
        

        while(n>0){
            int x= n%10;
            n/=10;
            sum += x;
            pro *= x;
        }
        sum += pro;

        return num%sum==0;

        
    }
};