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
    ListNode* deleteDuplicates(ListNode* head) {
        auto result = head;
        
        while (head) {
            if (head->next) {
                if (head->val == head->next->val) {
                    auto tmp = head->next;
                    head->next = head->next->next;
                    delete tmp;
                } else {
                    head = head->next;
                }
            } else {
                break;
            }
        }
        
        return result;
    }
};