class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> taskNums(26, 0);
        for (char task : tasks) {
            taskNums[task - 'A']++;
        }
        sort(taskNums.rbegin(), taskNums.rend());

        int gap = taskNums[0] - 1;
        int idle = gap * n;
        for (int i = 1; i < 26; i++) {
            idle -= min(gap, taskNums[i]);
        }

        return idle < 0 ? tasks.size() : tasks.size() + idle;
    }
};