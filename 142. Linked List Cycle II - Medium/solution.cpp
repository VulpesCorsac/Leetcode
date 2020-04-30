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
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) {
            return nullptr;
        }

        auto slow  = head;
        auto fast  = head;
        auto cycle = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                while(slow != cycle) {
                    slow  = slow->next;
                    cycle = cycle->next;
                }
                return cycle;
            }
        }
        return nullptr;  
    }
};