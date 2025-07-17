class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> myNums;
        vector<long long> res;
        unordered_map<long long, long long> mapping;
        
        for (int i = 0; i < nums1.size(); i++) {
            myNums.push_back({nums1[i], nums2[i]});
        }

        sort(myNums.begin(), myNums.end());

        priority_queue<int, vector<int>, greater<int>> minHeap;
        long long currMax = 0;
        
        mapping[myNums[0].first] = 0;
        minHeap.push(myNums[0].second);
        currMax += myNums[0].second;
        
        for (int i = 1; i < myNums.size(); i++) {
            if (myNums[i].first > myNums[i - 1].first) mapping[myNums[i].first] = currMax;

            if (minHeap.size() < k) {
                currMax += myNums[i].second;
                minHeap.push(myNums[i].second);
            }
            else if (minHeap.top() < myNums[i].second){
                currMax += myNums[i].second - minHeap.top();
                minHeap.pop();
                minHeap.push(myNums[i].second);
            }
        }

        for (int i = 0; i < nums1.size(); i++) {
            res.push_back(mapping[nums1[i]]);
        }

        return res;
    }
};