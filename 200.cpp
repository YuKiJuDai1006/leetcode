class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int h = grid.size();
        int w = grid[0].size();
        int res = 0;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(grid[i][j] == '1'){
                    ++res;
                    dfs(i, j, grid);
                }
            }
        }
        return res;

    }
    void dfs(int i, int j, vector<vector<char>>& grid){
        int h = grid.size();
        int w = grid[0].size();

        grid[i][j] = 0;
        if(i-1 >= 0 && grid[i-1][j] == '1') dfs(i-1, j, grid);
        if(i+1 < h && grid[i+1][j] == '1') dfs(i+1, j, grid);
        if(j-1 >= 0 && grid[i][j-1] == '1') dfs(i, j-1, grid);
        if(j+1 < w && grid[i][j+1] == '1') dfs(i, j+1, grid);
    }
};