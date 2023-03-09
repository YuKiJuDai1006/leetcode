class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int h = matrix.size();
        int w = matrix[0].size();
        int i = 0, j = w-1;
        while(i < h && j >= 0){
            if(matrix[i][j] == target) return 1;
            if(matrix[i][j] > target) --j;
            else ++i;
        }
        return 0;
    }
};