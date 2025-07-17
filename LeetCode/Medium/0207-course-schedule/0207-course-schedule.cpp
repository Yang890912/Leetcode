class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses);
        vector<int> visited(numCourses, 0);

        for (int i = 0; i < prerequisites.size(); i++) {
            adjList[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (visited[i] != 0) continue;
            visited[i] = 1;
            if (!dfs(adjList, visited, i)) return false;
            visited[i] = 2;
        }
        return true;
    }

    bool dfs(vector<vector<int>>& adjList, vector<int>& visited, int node) {
        for (int i = 0; i < adjList[node].size(); i++) {
            int neighbor = adjList[node][i];
            // cout << neighbor << " " << visited[neighbor] << endl;
            if (visited[neighbor] == 1) return false;
            else if (visited[neighbor] == 2) continue;
            else {
                visited[neighbor] = 1;
                if (!dfs(adjList, visited, neighbor)) return false;
                visited[neighbor] = 2;
            }
        }
        return true;
    }
};