/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);return 0;}();
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* prev_left = head;
        ListNode* left = head;
        ListNode* right = head;
        
        for (int i = 0; i < n; ++i) {
            right = right->next;
        }
        
        while (right) {
            if (left != head) {
                prev_left = prev_left->next;
            }
            left = left->next;
            right = right->next;
        }

        if (left == head) {
            if (left == right) {
                return nullptr;
            } else {
                auto result = left->next;

                delete left;
                
                return result;
            }
        }
        
        prev_left->next = left->next;
        
        delete left;
        
        return head;
    }
};