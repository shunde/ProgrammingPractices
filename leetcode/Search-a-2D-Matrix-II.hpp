class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m, n;
        // empty matrix
        if (!(m = matrix.size()) || !(n = matrix[0].size()))
            return false;

        int row = 0;
        int col = n - 1;
        while (row < m && col >= 0) {
            if (target < matrix[row][col])
                col--;
            else if (target > matrix[row][col])
                row++;
            else
                return true;
        }
        return false;
    }
};