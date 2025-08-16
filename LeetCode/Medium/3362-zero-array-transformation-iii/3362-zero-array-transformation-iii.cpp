class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        sort(queries.begin(), queries.end());
        priority_queue<int> tmp;
        priority_queue<int, vector<int>, greater<int>> assigned;

        int used = 0, j = 0;
        for (int i = 0; i < nums.size(); i++) {
            while (!assigned.empty() && assigned.top() < i) // 移掉用不到的
                assigned.pop();

            while (j < queries.size() && queries[j][0] <= i) // 暫時存可能用的到的 
                tmp.push(queries[j++][1]);

            while (assigned.size() < nums[i] && !tmp.empty() && tmp.top() >= i) { // 如果目前不夠消掉，從tmp拿來補
                assigned.push(tmp.top());
                tmp.pop();
                used++;
            }

            if (assigned.size() < nums[i]) return -1;
        }

        return queries.size() - used;
    }
};