class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int h = matrix.size();
        int w = matrix[0].size();
        int res = 0;
        for(int k = 0; k < h; k++){
            vector<int> heis;
            for(int j = 0; j < w; j++){
                int count = 0;
                int flag = 1;
                for(int i = k; i < h; i++){
                    if(matrix[i][j] == '0'){
                        flag = 0;
                        count = i - k;
                        break;
                    }
                }
                if(flag) count = h-k;
                heis.push_back(count);
            }
            res = max(res, largestRectangleArea(heis));
        }
        return res;   
    }


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