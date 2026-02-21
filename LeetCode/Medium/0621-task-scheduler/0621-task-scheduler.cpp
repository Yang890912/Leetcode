class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        int taskWithMax = 0;
        int maxFreq = 0;

        for (char t : tasks) {
            int key = t - 'A';
            freq[key]++;
             
            if (maxFreq == freq[key]) {
                taskWithMax++;
            }
            else if (maxFreq < freq[key]) {
                taskWithMax = 1;
                maxFreq = freq[key];
            }
        }

        int idle = (maxFreq - 1) * max(0, n - taskWithMax + 1);
        idle -= tasks.size() - maxFreq * taskWithMax;
        idle = max(0, idle);
        
        return tasks.size() + idle;
    }
};