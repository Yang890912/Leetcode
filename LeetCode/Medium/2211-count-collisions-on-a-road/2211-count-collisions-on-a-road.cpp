class Solution {
public:
    int countCollisions(string directions) {
        int res = 0;
        int left = 0; 
        int right = directions.size() - 1;

        while (left < directions.size() - 1 && directions[left] == 'L') left++;
        while (right > 0 && directions[right] == 'R') right--;

        for (int i = left; i <= right; i++) {
            if (directions[i] != 'S') res++;
        }

        return res;
    }
};