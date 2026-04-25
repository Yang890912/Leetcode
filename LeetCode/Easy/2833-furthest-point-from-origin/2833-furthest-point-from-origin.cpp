class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int dis = 0;
        int _num = 0;
        for (char& c : moves) {
            if (c == 'L') dis--;
            else if (c == 'R') dis++;
            else _num++;
        }

        return _num + abs(dis);
    }
};