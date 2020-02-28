static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);return 0;}();
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }
    
    void push(int x) {
        if (db.empty()) {
            db.push({x, x});
        } else {
            db.push({x, min(getMin(), x)});
        }
    }
    
    void pop() {
        db.pop();
    }
    
    int top() {
        return db.top().first;
    }
    
    int getMin() {
        return db.top().second;
    }
    
private:
    stack < pair < int, int > > db;    
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */