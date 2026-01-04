class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int res = 0;
        vector<int> eqTo4Divs(100001, 0);
        vector<bool> upTo4Divs(100001, false);

        for (int num : nums) {
            if (eqTo4Divs[num]) {
                res += eqTo4Divs[num];
                continue; 
            }

            if (upTo4Divs[num]) continue;

            int sum = 1 + num;
            int divs = 2;
            for (int p = sqrt(num); p >= 2; p--) {
                if (upTo4Divs[num] || eqTo4Divs[num]) break;
                if (num % p != 0) continue;

                if (p != num / p) {
                    sum += p + (num / p);
                    divs += 2; 
                }
                else {
                    sum += p;
                    divs += 1; 
                }

                if (divs > 4) break;
            }

            if (divs == 4) {
                res += sum;
                eqTo4Divs[num] = sum;
            }

            if (divs > 4) upTo4Divs[num] = true;
        }

        return res;
    }
};