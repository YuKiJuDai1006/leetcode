class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        if(!n) return 1;

        vector<int> inDe(numCourses);
        unordered_map<int, vector<int>> tab;
        for(int i = 0; i < n; i++){
            inDe[prerequisites[i][0]]++;
            tab[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        queue<int> qu;
        for(int i = 0; i < numCourses; i++){
            if(inDe[i] == 0){
                qu.push(i);
            }
        }
        int res = 0;
        while(qu.size()){
            int f = qu.front();
            qu.pop();
            ++res;
            for(int i = 0; i < tab[f].size(); i++){
                --inDe[tab[f][i]];
                if(inDe[tab[f][i]] == 0) qu.push(tab[f][i]);
            }
        }
        return res < numCourses ? 0 : 1;   
    } 
};