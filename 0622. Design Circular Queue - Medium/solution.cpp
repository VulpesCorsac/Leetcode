static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();

class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k)
        : head(0)
        , tail(0)
        , size(0)
        , capacity(k)
        , data(vector < int > (k)) {

    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }

        ++size;
        tail = (tail + 1) % capacity;
        data[tail] = value;

        if (size == 1) {
            head = tail;
        }

        return true;
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }

        --size;
        head = (head + 1) % capacity;

        if (size == 0) {
            tail = head;
        }

        return true;
    }

    /** Get the front item from the queue. */
    int Front() {
        if (isEmpty()) {
            return -1;
        }

        return data[head];
    }

    /** Get the last item from the queue. */
    int Rear() {
        if (isEmpty()) {
            return -1;
        }

        return data[tail];
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return !size;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return size == capacity;
    }

private:
    int head;
    int tail;
    int size;
    const int capacity;
    vector < int > data;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */