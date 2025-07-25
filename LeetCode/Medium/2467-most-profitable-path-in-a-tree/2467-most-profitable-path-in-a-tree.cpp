class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int numOfNodes = amount.size();
        vector<vector<int>> adjList(numOfNodes, vector<int>{});
        vector<int> pathOfBob;
        vector<int> BobPathMap(numOfNodes, INT_MAX);

        for (int i = 0; i < edges.size(); i++) {
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }

        findBobPath(pathOfBob, adjList, bob, -1);

        int time = 0;
        for (int i = pathOfBob.size() - 1; i >= 0; i--) {
            BobPathMap[pathOfBob[i]] = time++;
        }

        return findMaxProfitPath(BobPathMap, adjList, amount, 0, 0, -1);
    }

    bool findBobPath(vector<int>& pathOfBob, vector<vector<int>>& adjList, int x, int prex) {
        if (x == 0) {
            pathOfBob.push_back(x);
            return true;
        }    
        
        for (int i = 0; i < adjList[x].size(); i++) {
            if (adjList[x][i] == prex) continue;
 
            if (findBobPath(pathOfBob, adjList, adjList[x][i], x)) {
                pathOfBob.push_back(x);
                return true;
            }
        }

        return false;
    }

    int findMaxProfitPath(vector<int>& BobPathMap, 
                          vector<vector<int>>& adjList, 
                          vector<int>& amount, 
                          int time, int x, int prex) {
        int profit = 0;
        if (time == BobPathMap[x]) profit = amount[x] / 2;
        else if (time < BobPathMap[x]) profit = amount[x];

        int currMax = INT_MIN;
        bool isLeaf = true;
        for (int i = 0; i < adjList[x].size(); i++) {
            if (adjList[x][i] == prex) continue;
            // cout << x << " " << adjList[x][i] <<endl;
            isLeaf = false;
            currMax = max(currMax, findMaxProfitPath(BobPathMap, adjList, amount, time + 1, adjList[x][i], x));
            // cout << currMax <<endl;
        }

        return profit + (isLeaf ? 0 : currMax);

    }
};