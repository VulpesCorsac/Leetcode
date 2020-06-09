static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();

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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) {
            return head;
        }

        while (head && head->val == val) {
            head = head->next;
        }

        ListNode* prev = nullptr;
        auto tmp = head;
        while (tmp) {
            if (tmp->val == val) {
                if (prev) {
                    prev->next = tmp->next;
                }
            } else {
                prev = tmp;
            }
            tmp = tmp->next;
        }

        return head;
    }
};