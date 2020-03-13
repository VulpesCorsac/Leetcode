static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);return 0;}();

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* less_head    = nullptr;
        ListNode* less_tail    = nullptr;
        ListNode* greater_head = nullptr;
        ListNode* greater_tail = nullptr;
        
        while (head) {
            cout << head->val << " ";
            if (head->val < x) {
                if (!less_head) {
                    less_head = head;
                    less_tail = head;
                } else {
                    less_tail->next = head;
                    less_tail = head;
                }
            } else {
                if (!greater_head) {
                    greater_head = head;
                    greater_tail = head;
                } else {
                    greater_tail->next = head;
                    greater_tail = head;
                }
            }
            
            head = head->next;
        }
        
        if (less_tail) {
            less_tail->next = nullptr;
        }
        if (greater_tail) {
            greater_tail->next = nullptr;
        }
        
        if (less_head) {
            less_tail->next = greater_head;
            return less_head;
        } else {
            return greater_head;
        }
    }
};