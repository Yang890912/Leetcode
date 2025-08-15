class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());

        vector<string> res;
        res.push_back(folder[0]);

        for (int i = 1; i < folder.size(); i++) {
            string last = res.back();
            last += "/";

            if (folder[i].compare(0, last.length(), last)) res.push_back(folder[i]);
        }

        return res;
    }
};