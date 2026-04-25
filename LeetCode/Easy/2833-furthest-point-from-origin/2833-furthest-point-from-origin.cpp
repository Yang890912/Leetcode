class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int dis = 0;
        int _count = 0;
        for (char& c : moves) {
            if (c == 'L') dis--;
            else if (c == 'R') dis++;
            else _count++;
        }

        return _count + abs(dis);
    }
};