class Solution {
public:
    long long sumAndMultiply(int n) {
        int x = 0;
        int place = 1;
        while (n > 0) {
            int d = n % 10;
            n /= 10;
            if (d == 0) {
                continue;
            }
            x += (d * place);
            place *= 10;
        }
        int sum=0;
        int x1=x;
        while(x1>0){
           sum += x1%10;
           x1/=10; 
        }

        return (long long)sum*x;

    }
};