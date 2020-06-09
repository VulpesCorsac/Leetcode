static auto _ = [] () { ios_base::sync_with_stdio(false); cin.tie(nullptr); return 0; } ();

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head) {
            return true;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        fast = slow->next;

        slow->next = nullptr;

        for (ListNode *left = head, *right = reverseList(fast);
             left && right;
             left = left->next, right = right->next) {
            if (left->val != right->val) {
                return false;
            }
        }

        slow->next = fast;

        return true;
    }

private:
    ListNode* reverseList(ListNode *head) {
        ListNode *prev = nullptr;

        while (head) {
            auto tmp = head->next;
            head->next = prev;
            prev = head;
            head = tmp;
        }

        return prev;
    }
};