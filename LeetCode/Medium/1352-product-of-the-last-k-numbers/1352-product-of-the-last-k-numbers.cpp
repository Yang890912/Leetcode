class ProductOfNumbers {
public:
    vector<int> prefixProd;
    ProductOfNumbers() {
        prefixProd = {1};
    }
    
    void add(int num) {
        if (num == 0) prefixProd = {1};
        else prefixProd.push_back(num * prefixProd.back());
    }
    
    int getProduct(int k) {
        int p_size = prefixProd.size();
        if (k >= p_size) return 0;
        return prefixProd[p_size - 1] / prefixProd[p_size - 1 - k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */