/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) {
            return false;
        }
        
        auto slow = head;
        auto fast = head->next;
        
        while (slow != fast) {
            if (fast == nullptr || fast->next == nullptr) {
                return false;
            }    
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return true;
    }
};