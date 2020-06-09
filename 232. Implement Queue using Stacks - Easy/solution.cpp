static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        st2.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        auto ans = peek();

        st1.pop();

        return ans;
    }

    /** Get the front element. */
    int peek() {
        if (st1.empty()) {
            st2_to_st1();
        }

        return st1.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return st1.empty() && st2.empty();
    }

private:
    void st2_to_st1() {
        while (!st2.empty()) {
            st1.push(st2.top());
            st2.pop();
        }
    }

    stack < int > st1;
    stack < int > st2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */