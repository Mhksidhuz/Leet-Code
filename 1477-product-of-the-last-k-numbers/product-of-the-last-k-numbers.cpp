class ProductOfNumbers {

vector<int>arr;

public:
    ProductOfNumbers() {
    }
    
    void add(int num) {
        arr.push_back(num);
    }
    
    int getProduct(int k) {
        int ans =  1;
        int n = arr.size();
        for(int i=0;i<k;i++){
            ans *= arr[n-i-1];
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