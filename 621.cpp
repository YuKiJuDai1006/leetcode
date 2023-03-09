class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int sum = tasks.size();
        unordered_map<char, int> tab;
        for(char& ch : tasks) ++tab[ch];
        int h = 0;
        for(auto& it : tab){
            if(it.second > h) h = it.second;
        }
        int w = 0;
        for(auto& it : tab){
            if(it.second == h) ++w;
        }
        return max((h-1)*(n+1)+w, sum);
    }
};