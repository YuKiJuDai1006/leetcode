class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string str = "()";
        vector<string> coms;
        string com;
        backtrace(2*n, 0, com, str, coms);
        vector<string> res;
        for(string str : coms){
            if(isOk(str)) res.push_back(str);
        }
        return res;
    }

    void backtrace(int m, int lev, string com, string str, vector<string>& coms){
        if(lev == m){
            int count = 0;
            for(int i = 0; i < m; i++){
                if(com[i] == ')') count++;
            }
            if(count == m/2) coms.push_back(com);
            return;
        }
        for(char ch : str){
            com.push_back(ch);
            backtrace(m, lev+1, com, str, coms);
            com.pop_back();
        }
    }

    bool isOk(string str){
        stack<char> st;
        for(int i = 0; i < str.size(); i++){
            if(str[i] == '('){
                st.push(str[i]);
            }
            else{
                if(st.empty()) return 0;
                if(st.top() != '(') return 0;
                st.pop();
            }
        }
        if(!st.empty()) return 0;
        return 1;
    }
};