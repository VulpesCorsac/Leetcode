class Solution {
public:
    vector < vector < int > > generate(int numRows) {
        vector < vector < int > > ans(numRows);
        
        for (int row = 0; row < numRows; ++row) {
            vector < int > current_row(row+1, 1);
            
            for (int j = 1; j < row; ++j) {
                current_row[j] = ans[row-1][j-1] + ans[row-1][j];
            }
            
            ans[row] = std::move(current_row);
        }
        
        return ans;
    }
};