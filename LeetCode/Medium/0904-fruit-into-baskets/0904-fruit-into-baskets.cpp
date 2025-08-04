class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        vector<pair<int, int>> fruitTypesCounts;
        for (int i = 0; i < fruits.size(); i++) {
            pair<int, int> typesCounts;
            typesCounts.first = fruits[i];
            typesCounts.second = 1;
            
            int j = i + 1;
            while (j < fruits.size()) {
                if (fruits[j] != typesCounts.first) break;
                typesCounts.second++;
                j++;
            }

            fruitTypesCounts.push_back(typesCounts);
            i = j - 1;
        }

        int res = 0;
        int tmpRes = 0, firstType = 0, secondType = 0;
        for (int i = 0; i < fruitTypesCounts.size(); i++) {
            if (i == 0) {
                firstType = fruitTypesCounts[i].first;
                tmpRes += fruitTypesCounts[i].second;
            }
            else if (i == 1) {
                secondType = fruitTypesCounts[i].first;
                tmpRes += fruitTypesCounts[i].second;
            }
            else if (fruitTypesCounts[i].first == firstType || fruitTypesCounts[i].first == secondType) {
                tmpRes += fruitTypesCounts[i].second;
            }
            else {
                firstType = fruitTypesCounts[i - 1].first;
                secondType = fruitTypesCounts[i].first;
                tmpRes = fruitTypesCounts[i - 1].second + fruitTypesCounts[i].second;
            }

            res = max(res, tmpRes);
        }

        return res;
    }
};