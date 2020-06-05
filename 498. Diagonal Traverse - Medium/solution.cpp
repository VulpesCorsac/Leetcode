static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();
class Solution {
public:
    vector < int > findDiagonalOrder(vector < vector < int > >& matrix) {
        if (!matrix.size() || !matrix[0].size()) {
            return {};
        }
        
        vector < int > ans;
        
        const int N = matrix.size();
        const int M = matrix[0].size();
        
        int row = 0, column = 0;
        int direction = 1;
        
        while (row < N && column < M) {
            ans.push_back(matrix[row][column]);
            
            auto new_row    = row    + (direction ? -1 : +1);
            auto new_column = column + (direction ? +1 : -1);
            
            if (new_row < 0 || new_row == N || new_column < 0 || new_column == M) {
                if (direction) {
                    row    += (column == M - 1) ? 1 : 0;
                    column += (column <  M - 1) ? 1 : 0;                    
                } else {
                    column += (row == N - 1) ? 1 : 0;
                    row    += (row <  N - 1) ? 1 : 0;
                }
                
                direction = 1 - direction;
            } else {
                row    = new_row;
                column = new_column;                
            }
        }
        
        return ans;
    }
};