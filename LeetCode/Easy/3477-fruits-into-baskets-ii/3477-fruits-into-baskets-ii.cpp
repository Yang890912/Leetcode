class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int placed = 0;
        for (int fruit : fruits) {
            for (int i = 0; i < baskets.size(); i++) {
                if (baskets[i] < fruit) continue;
                else {
                    baskets[i] = 0;
                    placed++;
                    break;
                }
            }
        }

        return baskets.size() - placed;
    }
};