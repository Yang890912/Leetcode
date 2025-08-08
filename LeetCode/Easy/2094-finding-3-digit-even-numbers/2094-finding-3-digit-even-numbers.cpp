class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> digiNums(10, 0);
        for (int digit : digits) {
            digiNums[digit]++;
        }

        vector<int> res;
        for (int i = 1; i <= 9; i++) {
            if (digiNums[i] <= 0) continue;
            else digiNums[i]--;

            for (int j = 0; j <= 9; j++) {
                if (digiNums[j] <= 0) continue;
                else digiNums[j]--;

                for (int k = 0; k <= 9; k += 2) {
                    if (digiNums[k] <= 0) continue;
                    else res.push_back(100 * i + 10 * j + k);
                }
                digiNums[j]++;
            }
            digiNums[i]++;
        }

        return res;
    }
};