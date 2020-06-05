static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) {
            return nullptr;
        }
        
        if(m[head]) {
            return m[head];
        }
        
        m[head]         = new Node(head->val);
        m[head]->next   = copyRandomList(head->next);
        m[head]->random = copyRandomList(head->random);
        
        return m[head];        
    }

private:
    unordered_map < Node*, Node* > m;
};