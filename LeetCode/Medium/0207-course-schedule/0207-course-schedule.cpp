class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visited(numCourses, -1);
        vector<vector<int>> needed(numCourses);

        for (vector<int>& pre : prerequisites) {
            needed[pre[0]].push_back(pre[1]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 1) continue;
            if (!dfs(visited, needed, i)) return false;
        }

        return true;
    }

    bool dfs(vector<int>& visited, vector<vector<int>>& needed, int curr) {
        if (visited[curr] == 0) return false;
        if (visited[curr] == 1) return true;

        visited[curr] = 0;
        for (int pre : needed[curr]) {
            if (!dfs(visited, needed, pre)) return false;
        }
        visited[curr] = 1;

        return true;
    }
};