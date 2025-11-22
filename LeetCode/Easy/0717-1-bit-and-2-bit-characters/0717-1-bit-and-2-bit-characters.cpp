class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0;
        bool res = false;

        while (i < bits.size()) {
            if (bits[i] == 1) {
                i += 2;
                res = false;
            }
            else {
                i += 1;
                res = true;
            }
        }

        return res;
    }
};