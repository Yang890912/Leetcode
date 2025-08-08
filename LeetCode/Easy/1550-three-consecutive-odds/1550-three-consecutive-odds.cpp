class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int pos = -1;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] % 2 == 0) pos = -1;
            else if (arr[i] % 2 == 1) {
                if (pos == -1) pos = i;
                else if (i - pos >= 2) return true;
            }
        }

        return false;
    }
};