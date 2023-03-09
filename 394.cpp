class Solution {
public:
    string decodeString(string s) {
        stack<char> st1, st2;
        int n = s.size();
        if(n == 1 && s[0] - '0' <= 9) return "";
        for(int i = 0; i < n; i++){
            if(s[i] != ']') st1.push(s[i]);
            else{
                while(st1.top() != '['){
                    st2.push(st1.top());
                    st1.pop();
                }
                st1.pop();

                int t = 0;
                int c = 1;
                while(!st1.empty() && st1.top()-'0'>= 0 && st1.top()-'0' <= 9){
                    t = t + (st1.top()-'0')*c;
                    c *= 10;
                    st1.pop();
                }
                
                string tmp1;
                while(!st2.empty()){
                    tmp1.push_back(st2.top());
                    st2.pop();
                }
                string tmp2;
                for(int i = 0; i < t; i++) tmp2 += tmp1;
                for(int i = 0; i < tmp2.size(); i++) st1.push(tmp2[i]);
            }
        }

        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        string res;
        while(!st2.empty()){
            res += st2.top();
            st2.pop();
        }
        return res;
    }
};