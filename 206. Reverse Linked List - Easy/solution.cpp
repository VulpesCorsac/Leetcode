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
    ListNode* reverseList(ListNode* head) {
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