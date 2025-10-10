class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int res = numBottles;

        while (numBottles >= numExchange) {
            res += 1;
            numBottles = numBottles - numExchange + 1;
            numExchange++;
        }

        return res;
    }
};