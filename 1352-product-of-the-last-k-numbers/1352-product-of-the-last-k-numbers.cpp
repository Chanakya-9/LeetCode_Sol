class ProductOfNumbers {
    vector<int> arr={};
public:
    ProductOfNumbers() {
        arr={};
    }
    
    void add(int num) {
        if (num==0){
            arr={};
        }
        arr.push_back(num);
    }
    
    int getProduct(int k) {
        int n=arr.size();
        int ans=1;
        for(int i=n-1;k>0;--k){
            if(arr[i]==0){
                return 0;
            }
            ans*=arr[i--];
        }
        return ans;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */