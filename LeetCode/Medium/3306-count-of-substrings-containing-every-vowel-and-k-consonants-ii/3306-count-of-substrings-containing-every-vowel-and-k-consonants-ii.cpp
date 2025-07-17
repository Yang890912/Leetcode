class Solution {
public:
    long long countOfSubstrings(string word, int k) {
        return atLeastConsonants(word, k) - atLeastConsonants(word, k + 1);
    }

    long long atLeastConsonants(string word, int k) {
        unordered_map<char, int> vowelMap;
        long long res = 0;
        int numOfConsonants = 0;
        int left = 0;

        for (int i = 0; i < word.size(); i++) {
            if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || word[i] == 'u')
                vowelMap[word[i]]++;
            else numOfConsonants++;
            
            while (vowelMap.size() == 5 && numOfConsonants >= k) {
                res += word.size() - i;

                if (word[left] == 'a' || 
                    word[left] == 'e' || 
                    word[left] == 'i' || 
                    word[left] == 'o' || 
                    word[left] == 'u') {
                    vowelMap[word[left]]--;
                    if (vowelMap[word[left]] == 0) vowelMap.erase(word[left]);
                }
                else numOfConsonants--;
                
                left++;
            }
        }

        return res;
    }
};