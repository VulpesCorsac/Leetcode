class Solution {
public:
    int hammingDistance(int x, int y) {
        int result = 0;
        
        int bit = 1;
        for (int i = 0; i < 31; ++i) {
            int x_bit = x & bit;
            int y_bit = y & bit;
            
            result += (x_bit == y_bit ? 0 : 1);
            
            bit <<= 1;
        }
        
        return result;
    }
};