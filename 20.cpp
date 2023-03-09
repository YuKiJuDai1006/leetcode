class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] =='{' || s[i] == '[')
                    st.push(s[i]);
            else{
                if(st.empty()) return 0;
                if(s[i] == ')' && st.top() != '(') return 0;
                if(s[i] == '}' && st.top() != '{') return 0;
                if(s[i] == ']' && st.top() != '[') return 0;
                st.pop();
            }
        }
        if(!st.empty()) return 0;
        return 1;
    }
};