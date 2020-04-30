static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();

/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int N, M;
    
    int getAnsForRow(BinaryMatrix &binaryMatrix, int row) {
        if (binaryMatrix.get(row, M-1)) {
            int l = 0;
            int r = M-1;

            while (l <= r) {
                int m = l + (r - l) / 2;

                if (binaryMatrix.get(row, m)) {
                    r = m-1;
                } else {
                    l = m+1;
                }
            }

            return l;
        } else {
            return -1;
        }
    }
    
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        auto dimensions = binaryMatrix.dimensions();
        
        N = dimensions[0];
        M = dimensions[1];
        
        int ans = -1;
        
        for (int row = 0; row < N; ++row) {
            auto temp = getAnsForRow(binaryMatrix, row);
            
            if (temp >= 0 && (temp < ans || ans == -1)) {
                ans = temp;
            }
        }
        
        return ans;
    }
};