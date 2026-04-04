class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size() / rows;
        string res = "";

        int i = 0, j = 0;
        while (j < n) {
            int tmpj = j;
            while (i < rows && tmpj < n) {
                res += encodedText[i * n + tmpj];
                i++;
                tmpj++;
            }
            i = 0;
            j++;
        }

        while (res.size() > 0 && res.back() == ' ') res.pop_back();

        return res;
    }
};