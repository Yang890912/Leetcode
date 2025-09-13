class Solution {
public:
    bool doesAliceWin(string s) {
        priority_queue<int> pq;

        int count = 0;
        for (char c : s) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                count++;
            }
        }

        if (count == 0) return false;
        // if (count % 2 == 1) return true;
        return true;
    }
};