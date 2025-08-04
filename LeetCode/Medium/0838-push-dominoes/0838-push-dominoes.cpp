class Solution {
public:
    string pushDominoes(string dominoes) {
        int pos = 0;
        char direction = ' ';
        int i = 0;
        while (i < dominoes.size()) {
            if (dominoes[i] == 'L') {
                if (direction == ' ' || direction == 'L') {
                    fill(dominoes.begin() + pos, dominoes.begin() + i + 1, 'L');
                }
                else if (direction == 'R') {
                    if ((i + pos) % 2 == 0) {
                        fill(dominoes.begin() + pos, dominoes.begin() + (i + pos) / 2, 'R');
                        fill(dominoes.begin() + (i + pos) / 2 + 1, dominoes.begin() + i + 1, 'L');
                    }
                    else {
                        fill(dominoes.begin() + pos, dominoes.begin() + (i + pos) / 2 + 1, 'R');
                        fill(dominoes.begin() + (i + pos) / 2 + 1, dominoes.begin() + i + 1, 'L');
                    }
                }
                pos = i;
                direction = dominoes[i];
            }
            else if (dominoes[i] == 'R') {
                if (direction == 'R') {
                    fill(dominoes.begin() + pos, dominoes.begin() + i + 1, 'R');
                }
                pos = i;
                direction = dominoes[i];
            }
            
            i++;
        }

        if (direction == 'R') fill(dominoes.begin() + pos, dominoes.end(), 'R');

        return dominoes;
    }
};