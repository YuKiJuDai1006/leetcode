class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int n = temperatures.size();
        vector<int> res(n);
        st.push(0);
        for(int i = 1; i < n; i++){
            while(!st.empty() && temperatures[i] > temperatures[st.top()]){
                int t = st.top();
                res[t] = i-t;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            int t = st.top();
            res[t] = 0;
            st.pop();
        }
        return res;
    }
};