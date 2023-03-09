class Solution {
public:
    bool res = 0;
    bool exist(vector<vector<char>>& board, string word) {
        int h = board.size();
        int l = board[0].size();
        int walk[h][l] = 0;
        dfs();
        return res;
    }
    void dfs(int h, int l, int hi, int li, vector<vector<char>>& board,
        vector<vector<int>>& walk, string& word, int idx){
        if(board[hi][li] == word[idx]) idx++;
        if(idx == word.size()){
            res = 1;
            return;
        }
        if(board[hi][li] == word[idx]){
            walk[hi][li] = 1;
            if()
        }
    }
};