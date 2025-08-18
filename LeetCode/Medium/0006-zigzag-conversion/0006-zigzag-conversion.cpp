class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        vector<string> subStrs(numRows, "");
        bool isAdd = true;
        int j = 0;  
        for (int i = 0; i < s.size(); i++) {
            subStrs[j] += s[i];

            if (!isAdd) {
                if (j == 0) {
                    isAdd = true;
                    j++;
                }
                else j--;
            }
            else if (isAdd) {
                if (j == numRows - 1) {
                    isAdd = false;
                    j--;
                }
                else j++;
            } 
        }

        string res = "";
        for (int i = 0; i < numRows; i++) res += subStrs[i];

        return res;
    }
};