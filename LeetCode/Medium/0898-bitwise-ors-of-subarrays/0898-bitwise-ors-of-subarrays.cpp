class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> res;
        unordered_set<int> curr;

        for (int num : arr) {
            unordered_set<int> next;
            next.insert(num);

            for (int prev : curr) {
                 next.insert(prev | num);
            }
            curr = next;

            res.insert(curr.begin(), curr.end());
        }

        return res.size();
    }
};