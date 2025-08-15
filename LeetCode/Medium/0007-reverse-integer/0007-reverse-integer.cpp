class Solution {
public:
    int reverse(int x) {
        int number;

        string s = to_string(x);
        int end = s.size() - 1;
        int start = 0;
        if (s == "0") return 0;
        if (s[start] == '-') start++;
        while (s[end] == '0') end--;

        string revs = s.substr(start, end - start + 1);
        std::reverse(revs.begin(), revs.end());

        if (s[0] == '-') revs = "-" + revs;

        try {
            number = stoi(revs);
            return number;
        } catch (const std::out_of_range& e) {
            return 0;
        }
    }
};