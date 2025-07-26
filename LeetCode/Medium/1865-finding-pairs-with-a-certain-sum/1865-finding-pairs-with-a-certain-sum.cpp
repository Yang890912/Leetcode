class FindSumPairs {
public:
    vector<int> myNums1, myNums2;
    unordered_map<int, int> nums1Freq, nums2Freq;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for (int num : nums1) {
            myNums1.push_back(num);
            nums1Freq[num]++;
        }

        for (int num : nums2) {
            myNums2.push_back(num);
            nums2Freq[num]++;
        }
    }
    
    void add(int index, int val) {
        nums2Freq[myNums2[index]]--;
        myNums2[index] += val;
        nums2Freq[myNums2[index]]++;
    }
    
    int count(int tot) {
        int res = 0;
        for (const auto& pair : nums1Freq) {
            if (nums2Freq.count(tot - pair.first)) {
                res += nums1Freq[pair.first] * nums2Freq[tot - pair.first];
            }
        }

        return res;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */