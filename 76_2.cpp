class Solution {
public:
    unordered_map<char, int> oi, ci;
    string minWindow(string s, string t) {
        for(char ch : s){
            oi[ch]++;
        }
        int l = 0, r = 0;
        int ansL = -1;
        int len = INT_MAX;
        while(r < s.size()){
            if(t.find(s[r])){
                ci[s[r]]++;
                r++;
            }
            while(check() && l <= r){
                if(r-l+1 < len){
                    len = r-l+1;
                    ansL = l;
                }
                if(t.find(s[l])){
                    ci[s[l]]--;
                }
                l++;
            }
        }
        if(ansL == -1) return string();
        return s.substr(ansL, len);

    }
    bool check(){
        for(auto& it : oi){
            if(ci[it.first] < it.second) return 0;
        }
        return 1;
    }
};