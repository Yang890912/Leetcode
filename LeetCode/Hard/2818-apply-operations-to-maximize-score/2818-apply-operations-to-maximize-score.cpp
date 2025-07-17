class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 1;
        const int MOD = 1e9 + 7;
        vector<int> scores(n, 0);
        vector<int> left(n, -1);
        vector<int> right(n, n);
        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < nums.size(); i++) {
            scores[i] = primeScore(nums[i]);
            pq.push({nums[i], i});
        }

        stack<pair<int, int>> stk;

        for (int i = 0; i < nums.size(); i++) {
            while (!stk.empty() && stk.top().first < scores[i]) stk.pop();
            if (!stk.empty()) left[i] = stk.top().second;
            stk.push({scores[i], i});
        }
        
        while (!stk.empty()) stk.pop();

        for (int i = nums.size() - 1; i >= 0; i--) {
            while (!stk.empty() && stk.top().first <= scores[i]) stk.pop();
            if (!stk.empty()) right[i] = stk.top().second;
            stk.push({scores[i], i});
        }

        while (k > 0 && !pq.empty()) {
            int num = pq.top().first;
            int idx = pq.top().second;
            pq.pop();
            long long s = 1LL * (right[idx] - idx) * (idx - left[idx]);
            long long steps = min((long long)k, s);
            long long multiply = modPow(num, (int)steps, MOD);

            res = (int)((1LL * res * multiply) % MOD);

            k -= steps;
        }

        return res % MOD;
    }

    int modPow(int base, int exp, int mod) {
        long long result = 1;
        long long b = base % mod;
        while (exp > 0) {
            if (exp & 1) {
                result = (result * b) % mod;
            }
            b = (b * b) % mod;
            exp >>= 1;
        }
        return (int)result;
    }

    int primeScore(int n) {
        int score = 0;
        for(int i = 2; i <= sqrt(1e5); i++) {
            if(n % i == 0) score++;
            while(n % i == 0) n /= i;
        }

        if(n > 1) score++;

        return score;
    }
};