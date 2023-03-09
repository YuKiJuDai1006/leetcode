class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if(n == 1) return heights[0];
        int res = 0;

        stack<int> st;
        st.push(0);
        for(int i = 1; i < n; i++){
            while(!st.empty() && heights[i] <= heights[st.top()]){
                int hi = heights[st.top()];
                st.pop();
                int fi = st.empty() ? -1 : st.top();
                int wi = i - fi - 1;
                res = max(res, hi * wi);
            }
            st.push(i);
        }

        int l;
        if(!st.empty()) l = st.top();

        while(!st.empty()){
            // h
            int hi = heights[st.top()];

            st.pop();
            int fi = st.empty() ? -1 : st.top();

            // w
            int wi = l - fi;
            res = max(res, hi * wi);
        }
        return res;
    }
};