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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2) {
            if (!carry) {
                return nullptr;
            } else {
                ListNode* result = new ListNode(carry);

                carry = result->val / 10;
                result->val %= 10;

                result->next = addTwoNumbers(nullptr, nullptr);

                return result;
            }
        }

        if (l1 && !l2) {
            ListNode* result = new ListNode(l1->val + carry);

            carry = result->val / 10;
            result->val %= 10;

            result->next = addTwoNumbers(nullptr, l1->next);

            return result;
        }
        if (!l1 && l2) {
            ListNode* result = new ListNode(l2->val + carry);

            carry = result->val / 10;
            result->val %= 10;

            result->next = addTwoNumbers(nullptr, l2->next);

            return result;
        }

        ListNode* result = new ListNode(l1->val + l2->val + carry);

        carry = result->val / 10;
        result->val %= 10;

        result->next = addTwoNumbers(l1->next, l2->next);

        return result;
    }

    int carry = 0;
};