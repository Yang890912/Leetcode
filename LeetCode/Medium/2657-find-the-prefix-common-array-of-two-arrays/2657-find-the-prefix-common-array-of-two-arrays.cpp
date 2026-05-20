class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        int cur = 0;
        vector<int> res;
        vector<int> table(51, 0);

        for (int i = 0; i < n; i++) {
            table[A[i]]++;
            table[B[i]]++;
            if (A[i] == B[i]) cur++;
            else {
                if (table[A[i]] == 2) cur++;
                if (table[B[i]] == 2) cur++;
            }

            res.push_back(cur);
        }

        return res;
    }
};