class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;
        int currPos = start;
        int currGas = 0;
        int remainCost = 0;

        while (start < gas.size()) {
            currGas += gas[currPos];
            currGas -= cost[currPos];

            if (currPos == gas.size() - 1) {
                if (currGas - remainCost < 0) return -1;
                else return start;
            }

            if (currGas < 0) {
                remainCost -= currGas;
                currGas = 0;
                start = currPos + 1;
                currPos = start;
                continue;
            }

            currPos++;
        }

        return -1;
    }
};