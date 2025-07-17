class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> mergedAccounts;
        vector<bool> visited(accounts.size(), false);

        for (int i = 0; i < accounts.size(); i++) {
            if (visited[i]) continue;

            unordered_set<string> emails;
            string name = accounts[i][0];
            visited[i] = true;

            for (int j = 1; j < accounts[i].size(); j++) {
                emails.insert(accounts[i][j]);
            }

            dfs(accounts, name, emails, visited);
            
            vector<string> account;
            vector<string> vEmails(emails.begin(), emails.end());
            sort(vEmails.begin(), vEmails.end());
            account.push_back(name);
            account.insert(account.end(), vEmails.begin(), vEmails.end());
            mergedAccounts.push_back(account);
        }

        return mergedAccounts;
    }

    void dfs(vector<vector<string>>& accounts, string name, unordered_set<string>& emails, vector<bool>& visited) {
        for (int i = 0; i < accounts.size(); i++) {
            if (visited[i] || accounts[i][0] != name) continue;
            
            visited[i] = true;
            bool isFound = false;

            for (int j = 1; j < accounts[i].size(); j++) {
                if (emails.count(accounts[i][j]) == 1) {
                    isFound = true;
                    break;
                }
            }

            if (!isFound) visited[i] = false;
            else {
                for (int j = 1; j < accounts[i].size(); j++) {
                    emails.insert(accounts[i][j]);
                }
                dfs(accounts, name, emails, visited);
            }
        }
    }
};