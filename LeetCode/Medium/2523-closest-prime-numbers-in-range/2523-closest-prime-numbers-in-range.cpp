class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> isPrime(1000001, true);
        vector<int> vec;
        vector<int> res(2, -1);

        isPrime[0] = false;
        isPrime[1] = false;
        for (int i = 2; i < sqrt(1000001); i++) {
            if (isPrime[i]) {
                for (int j = i * i; j < 1000001; j += i) isPrime[j] = false;
            }
        }

        int currMin = 1000001;
        for (int i = left; i <= right; i++) {
            if (isPrime[i]) vec.push_back(i);
            if (vec.size() < 2) continue;

            int right = vec.back();
            vec.pop_back();
            int left = vec.back();
            vec.pop_back();

            if (right - left < currMin) {
                currMin = right - left;
                res[0] = left;
                res[1] = right;
            }

            vec.push_back(right);
        }

        return res;
    }
};