class Solution {
public:
    int numTilePossibilities(string tiles) {
        unordered_set<string> sequences;
        vector<bool> visited(tiles.size(), false);

        for (int i = 0; i < tiles.size(); i++) {
            visited[i] = true;
            string sequence = "";
            sequence += tiles[i];
            dfs(sequences, visited, tiles, sequence);
            visited[i] = false;
        }

        return sequences.size();
    }

    void dfs(unordered_set<string>& sequences, vector<bool>& visited, string tiles, string sequence) {
        sequences.insert(sequence);
        for (int i = 0; i < tiles.size(); i++) {
            if (visited[i]) continue;
            visited[i] = true;
            sequence += tiles[i];
            dfs(sequences, visited, tiles, sequence);
            visited[i] = false;
            sequence.pop_back();
        }
    }
};