class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        stack<int> st;
        st.push(-1);

        for (int i = 0; i < heights.size(); i++) {
            while (st.top() != -1 && heights[i] < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();
                int w = i - st.top() - 1;
                res = max(res, h * w);
            }
            st.push(i);
        }

        while (st.top() != -1) {
            int h = heights[st.top()];
            st.pop();
            int w = heights.size() - st.top() - 1;
            res = max(res, h * w);
        }

        return res;
    }
};