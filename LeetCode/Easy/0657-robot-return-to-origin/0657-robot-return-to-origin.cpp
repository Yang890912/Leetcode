class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        for (char c : moves) {
            if (c == 'L') x -= 1;
            else if (c == 'R') x += 1;
            else if (c == 'U') y += 1;
            else if (c == 'D') y -= 1;
        }
        return (x == 0 && y == 0);
    }
};