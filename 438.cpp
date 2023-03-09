class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int sn = s.size();
        int pn = p.size();
        if(sn < pn) return {};
        vector<int> ans;
        
        vector<int> sc(26);
        vector<int> pc(26);
        for(int i = 0; i < pn; i++){
            sc[s[i]-'a']++;
            pc[p[i]-'a']++;
        }
        if(sc == pc) ans.push_back(0);
        for(int i = 0; i < sn-pn; i++){
            sc[s[i]-'a']--;
            sc[s[i+pn]-'a']++;
            if(sc == pc) ans.push_back(i+1);
        }
        return ans;
    }
};