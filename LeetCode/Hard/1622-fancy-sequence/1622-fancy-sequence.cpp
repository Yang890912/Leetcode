class Fancy {
public:
    const long long MOD = 1e9 + 7;
    long long x;
    long long y;
    vector<long long> v;

    Fancy() {
        x = 1;
        y = 0;
    }
    
    long long modInv(long long x) {
        long long res = 1;
        long long e = MOD - 2;
        while (e) {
            if (e & 1) res = res * x % MOD;
            x = x * x % MOD;
            e >>= 1;
        }
        return res;
    }

    void append(int val) {
        long long num = (val - y + MOD) % MOD;
        num = (num * modInv(x) + MOD) % MOD;
        v.push_back(num);
    }
    
    void addAll(int inc) {
        y = (y + inc) % MOD;
    }
    
    void multAll(int m) {
        x = x * m % MOD;
        y = y * m % MOD;
    }
    
    int getIndex(int idx) {
        if (idx >= v.size()) return -1;
        return (x * v[idx] + y) % MOD;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */