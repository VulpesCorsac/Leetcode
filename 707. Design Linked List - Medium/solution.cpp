static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);return 0;}();

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    MyLinkedList() {        
        size = 0;
        
        head = tail = nullptr;
    }
    
    ~MyLinkedList() {
//        return;
        
        while (size > 0) {
            deleteAtIndex(0);
        }   
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        print("Before get(" + to_string(index) + ")");

        auto node = getNode(index);
        
        if (!node) {
            return -1;
        }
        
        return node->val;

        print("After get(" + to_string(index) + ")");
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
//        cout << "addAtHead(" + to_string(val) + "): ";
        return addAtIndex(0, val);
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
//        cout << "addAtTail(" + to_string(val) + "): ";
        return addAtIndex(size, val);        
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        print("Before addAtIndex(" + to_string(index) + ", " + to_string(val) + ")");

        if (index > size || index < 0) {
            return;
        }
        
        auto temp = new Node(val);

        if (size == 0) {
            head = temp;
            tail = temp;
        } else if (index == 0) {
            temp->next = head;
            head->prev = temp;
            
            head = temp;
        } else if (index == size) {
            temp->prev = tail;
            tail->next = temp;
            
            tail = temp;
        } else {
            auto node = getNode(index);
            
            temp->prev = node->prev;
            node->prev->next = temp;
            
            temp->next = node;
            node->prev = temp;
        }
        
        ++size;

        print("After addAtIndex(" + to_string(index) + ", " + to_string(val) + ")");
        
        return;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        print("Before deleteAtIndex(" + to_string(index) + ")");

        if (index >= size || index < 0) {
            return;
        }
        
        if (index == 0) {
            if (size > 1) {
                auto new_head = head->next;
                new_head->prev = nullptr;

                delete head;

                head = new_head;
            } else {
                delete head;
                
                head = nullptr;
            }
        } else if (index == size-1) {
            auto new_tail = tail->prev;
            new_tail->next = nullptr;
            
            delete tail;
            
            tail = new_tail;
        } else {
            auto node = getNode(index);
                        
            node->prev->next = node->next;
            node->next->prev = node->prev;
            
            delete node;
        }
        
        --size;

        print("After deleteAtIndex(" + to_string(index) + ")");
    }

private:
    class Node {
    public:
        Node(int val) : val(val), next(nullptr), prev(nullptr) {}
        
        int val;
        
        Node* next;
        Node* prev;
    };
    
    Node* getNode(int index) {
        if (index < 0 || index >= size) {
            return nullptr;
        }
        
        if (index <= size/2) {
            auto current = head;
            for (int i = 0; i != index; ++i) {
                current = current->next;
            }
    
            return current;
        } else {
            auto current = tail;
            for (int i = size-1; i != index; --i) {
                current = current->prev;
            }
    
            return current;
        }
    }
    
    void print(string text = "") {
        return;
        
        cout << text << " - ";
        cout << "Size: " << size << " ";
        
        auto node = head;
        cout << "[";
        while (node != nullptr) {
            cout << " " << node->val;
            node = node->next;
        }
        cout << " ]" << endl;
        
        return;
    }
    
    int size;
    
    Node* head;
    Node* tail;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */