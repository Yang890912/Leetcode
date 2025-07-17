#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> pos1(n, 0);

        for (int i = 0; i < n; i++) {
            pos1[nums1[i]] = i;
        }

        long long res = 0;
        ordered_set<int> st;

        for (int i = 0; i < n; i++) {
            int num2 = nums2[i];
            int idxIn1 = pos1[num2];
            
            int left = st.order_of_key(idxIn1);
            int right = (n - 1 - idxIn1) - (i - left);  // (#numbers in the right of nums1) - (this number in the left of nums2)
            res += (long long) left * right;

            st.insert(idxIn1);
        }

        return res;
    }
};