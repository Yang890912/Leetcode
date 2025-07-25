class Solution {
public:
    int balancedString(string s) {
        unordered_map<int, int> count;
        int n = s.size();
        int j = 0;
        int res = n;

        for (int i = 0; i < n; i++) {
            count[s[i]]++;
        }

        for (int i = 0; i < n; i++) {
            count[s[i]]--;
            while (j < n && count['Q'] <= n / 4 
                         && count['W'] <= n / 4 
                         && count['E'] <= n / 4 
                         && count['R'] <= n / 4) {
                
                res = min(res, i - j + 1);
                count[s[j++]]++;
            }
        }

        return res;
    }
};