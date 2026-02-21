class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);

        for (char& t : tasks) freq[t - 'A']++;

        sort(freq.rbegin(), freq.rend());

        int hole = freq[0] - 1;
        int idle = hole * n;
        for (int i = 1; i < 26; i++) {
            idle -= min(hole, freq[i]); // 分散撒在洞
        }
        
        return tasks.size() + max(idle, 0);
    }
};