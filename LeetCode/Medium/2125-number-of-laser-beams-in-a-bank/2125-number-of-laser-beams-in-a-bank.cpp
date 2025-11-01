class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int numberOfDev = 0;
        int res = 0;

        for (string s : bank) {
            int cnt = count(s.begin(), s.end(), '1');
            
            if (cnt == 0) continue;

            res += numberOfDev * cnt;
            numberOfDev = cnt;
        }

        return res;
    }
};