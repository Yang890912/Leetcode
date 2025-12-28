class Solution {
public:
    int bestClosingTime(string customers) {
        int penalty = 0;
        for (char c : customers) {
            if (c == 'N') penalty++;
        }

        int res = customers.size();
        int minPenalty = penalty;
        for (int i = customers.size() - 1; i >= 0; i--) {
            if (customers[i] == 'Y') penalty++;
            else penalty--;

            if (penalty <= minPenalty) {
                res = i;
                minPenalty = penalty;
            }
        }

        return res;
    }
};