class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> m;
        int n = matrix.size();
        vector<int> com;
        for(int j = 0; j < n ; j++){
            vector<int> com;
            for(int i = n - 1; i >= 0; i--){
                com.push_back(matrix[i][j]);
            }
            m.push_back(com);
        }
        matrix = m;
    }
};