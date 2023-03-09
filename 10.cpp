class Solution {
public:
    bool isMatch(string s, string p) {
        int n1 = s.size();
        int n2 = p.size();
        int i = 0, j = 0;
        bool match = 1;
        while(i < n1 && j < n2){
            if(s[i] == p[j]){
                i++;
                j++;
                continue;
            }

            if(p[j] != '.' && p[j] != '*'){
                if(j+1 < n2 && p[j+1] == '*'){
                    j+=2;
                    continue;
                }
                match = 0;
                break;
            }

            if(p[j] == '.'){
                i++;
                j++;
                continue;
            }

            if(p[j] == '*'){
                char pre = p[j-1];
                if(pre == s[i] || pre == '.'){
                    i++;
                    if(i < n1 && s[i] != s[i-1]) j++;
                    if(i >= n1) j++;
                    continue;
                }
                else{
                    match = 0;
                    break;
                }
            }

        }
        if(i < n1 || j < n2) match = 0;

        return match;
    }
};