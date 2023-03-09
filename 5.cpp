class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int len = 0;
        string res;
        for(int i = 0; i < n; i++){
            int li = i, ri = i;
            int tlen = 0;
            while(li >= 0 && ri <= n-1){
                if(s[li] == s[ri]){
                    tlen  = ri - li + 1;
                    li--;
                    ri++;
                }
                else break;
            }
            if(tlen > len){
                len = tlen;
                res = s.substr(li+1, len);
            }
        }

        for(int i = 0; i < n; i++){
            int li = i, ri = i + 1;
            int tlen = 0;
            while(li >= 0 && ri <= n-1){
                if(s[li] == s[ri]){
                    tlen = ri - li + 1;
                    li--;
                    ri++;
                }
                else break;
            }
            if(tlen > len){
                len = tlen;
                 res = s.substr(li+1, len);
            }
        }
        return res;
    }
};