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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* tmp = head;
        ListNode* last = nullptr;
        int list_length = 0;
        while (tmp) {
            ++list_length;
            last = tmp;
            tmp = tmp->next;
        }

        if (list_length <= 1) {
            return head;
        }

        k %= list_length;
        if (k == 0) {
            return head;
        }

        k = list_length - k;

        tmp = head;
        ListNode* prev = nullptr;
        for (int i = 0; i < k; ++i) {
            prev = tmp;
            tmp = tmp->next;
        }

        prev->next = nullptr;
        last->next = head;

        return tmp;
    }
};