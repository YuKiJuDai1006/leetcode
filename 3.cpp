class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int res = 0;
        int index = 0;
        for(int i = 0; i < n; i++){
            for(int j = index; j < i; j++){
                if(s[j] == s[i])
                    index = j + 1;
            }
            res = max(i - index + 1, res);
        }
        return res;
    }
};