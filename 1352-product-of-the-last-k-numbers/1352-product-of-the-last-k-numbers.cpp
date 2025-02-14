class ProductOfNumbers {
public:
    stack<int>ans;
    stack<int>rev;
    ProductOfNumbers() {}
    
    void add(int num) {
        ans.push(num);
    }
    
    int getProduct(int k) {
        int product=1;
        while(k--){
            product*=ans.top();
            rev.push(ans.top());
            ans.pop();
        }
        while(!rev.empty()){
            ans.push(rev.top());
            rev.pop();
        }
        return product;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */