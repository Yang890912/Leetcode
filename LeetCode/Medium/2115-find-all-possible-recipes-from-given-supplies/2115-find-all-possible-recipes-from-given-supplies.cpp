class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, bool> canCreate;
        unordered_map<string, int> recipeToIndex;
        vector<string> res;

        for (int i = 0; i < supplies.size(); i++) {
            canCreate[supplies[i]] = true;
        }

        for (int i = 0; i < recipes.size(); i++) {
            recipeToIndex[recipes[i]] = i;
        }
        
        for (int i = 0; i < recipes.size(); i++) {
            unordered_set<string> visited;
            visited.insert(recipes[i]);
            canCreate[recipes[i]] = dfs(recipes[i], ingredients, canCreate, recipeToIndex, visited);
            
            if (canCreate[recipes[i]]) res.push_back(recipes[i]);     
        }
        
        return res;
    }

    bool dfs(string recipe,
             vector<vector<string>>& ingredients,
             unordered_map<string, bool>& canCreate, 
             unordered_map<string, int>& recipeToIndex, 
             unordered_set<string>& visited) {
        
        if (canCreate.count(recipe)) {
            if (canCreate[recipe]) return true;
            else return false;
        }
        
        int idx = recipeToIndex[recipe];

        for (int i = 0; i < ingredients[idx].size(); i++) {
            string ingredent = ingredients[idx][i];

            if (canCreate.count(ingredent)) {
                if (canCreate[ingredent]) continue;
                else return false;
            }
            else if (canCreate.count(ingredent) == 0 && recipeToIndex.count(ingredent) == 0) return false;
            else {
                if (visited.count(ingredent)) return false;

                visited.insert(ingredent);
                canCreate[ingredent] = dfs(ingredent, ingredients, canCreate, recipeToIndex, visited);

                if (!canCreate[ingredent]) return false;
            }
        }

        return true;
    }
};