static auto _ = [] () {ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
    vector < vector < int > > kClosest(vector < vector < int > > & points, int K) const {
        sort(points, 0, points.size()-1, K);
        points.resize(K);
        return points;
    }
    
    void sort(vector < vector < int > > & points, int i, int j, int K) const {        
        if (i >= j) {
            return;
        }
        
        int k = i + (j - i) / 2;
        swap(points[i], points[k]);
    
        int mid = partition(points, i, j);
        
        int left_length = mid - i + 1;
        
        if (K < left_length) {
            sort(points, i, mid - 1, K);
        } else if (K > left_length) {
            sort(points, mid + 1, j, K - left_length);
        }
    }
    
    int partition(vector < vector < int > > & points, int i, int j) const {
        auto old_i = i;
        auto pivot = dist(points[i]);
        ++i;

        while (true) {
            while (i < j && dist(points[i]) < pivot) {
                ++i;
            }
            while (i <= j && dist(points[j]) >= pivot) {
                --j;
            }
            
            if (i >= j) {
                break;                
            }
            
            swap(points[i], points[j]);
        }
        
        swap(points[old_i], points[j]);
        
        return j;
    }    
    
    int dist(const vector < int > & point) const {
        return point[0]*point[0] + point[1]*point[1];
    }
};