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
    ListNode* middleNode(ListNode* head) {
        auto tmp = head;
        int length = 0;
        while (tmp) {
            ++length;
            tmp = tmp->next;
        }
        
        length = length / 2;
        
        tmp = head;
        
        for (int i = 0; i < length; ++i) {
            tmp = tmp->next;
        }
        
        return tmp;
    }
};