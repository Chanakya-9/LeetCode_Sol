class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int bp=prices[0];
       int profit=0;
       int n=prices.size();

       for(int i=0;i<n;i++){
            if(prices[i]<bp){
                bp=prices[i];
            }
            if((prices[i]-bp)>profit){
                profit=prices[i]-bp;
            }
       } 
       return profit;
    }
};