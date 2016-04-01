class NumMatrix {    
public:
    NumMatrix(vector<vector<int>> &matrix) {
        int m = 0, n = 0;
        if (!(m = matrix.size()) || !(n = matrix[0].size())) return;
        
        accSum.resize(m+1, vector<int>(n+1, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                accSum[i+1][j+1] = matrix[i][j] + accSum[i][j+1] + accSum[i+1][j] - accSum[i][j];
            }
        }        
    }


    int sumRegion(int row1, int col1, int row2, int col2) {
        return accSum[row2+1][col2+1] - accSum[row1][col2+1] - accSum[row2+1][col1] + accSum[row1][col1];        
    }
private:
    vector<vector<int>> accSum;
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);