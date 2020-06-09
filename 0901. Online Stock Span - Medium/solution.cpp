static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();

class StockSpanner {
public:
    vector < pair < int, int > > data;

    StockSpanner() {

    }

    int next(int price) {
        int span = 1;

        int index = data.size() - 1;

        while(index >= 0 && price >= data[index].first) {
            span  += data[index].second;
            index -= data[index].second;
        }

        data.push_back(make_pair(price, span));
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */