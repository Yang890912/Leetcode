class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int res = 0;
        int i = 1;
        
        while (i < neededTime.size()) {
            if (colors[i] != colors[i - 1]) {
                i++;
                continue;
            }

            int maxTime = max(neededTime[i], neededTime[i - 1]);
            int sumOfTime = neededTime[i] + neededTime[i - 1];
            i++;

            while (i < neededTime.size() && colors[i] == colors[i - 1]) {
                maxTime = max(neededTime[i], maxTime);
                sumOfTime += neededTime[i];
                i++;
            }

            res += sumOfTime - maxTime;
        }

        return res;
    }
};