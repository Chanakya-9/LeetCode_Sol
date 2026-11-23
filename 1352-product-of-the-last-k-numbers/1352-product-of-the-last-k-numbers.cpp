class ProductOfNumbers {
    vector<int> arr={};
public:
    ProductOfNumbers() {
        arr={};
    }
    
    void add(int num) {
        arr.push_back(num);
    }
    
    int getProduct(int k) {
        int n=arr.size();
        int ans=1;
        for(int i=n-1;k>0;--k){
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