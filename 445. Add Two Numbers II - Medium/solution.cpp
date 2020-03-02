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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack < int > n1 = listToStack(l1);
        stack < int > n2 = listToStack(l2);
        
        int overflow = 0;
        ListNode* ans = nullptr;
        while (!n1.empty() || !n2.empty()) {
            if (!n1.empty()) {
                overflow += n1.top();
                n1.pop();
            }
            if (!n2.empty()) {
                overflow += n2.top();
                n2.pop();
            }
            
            if (ans) {
                auto tmp = new ListNode(overflow % 10);
                tmp->next = ans;
                ans = tmp;
            } else {
                ans = new ListNode(overflow % 10);
            }

            overflow /= 10;
        }
        
        while (overflow) {
            auto tmp = new ListNode(overflow % 10);
            tmp->next = ans;
            ans = tmp;
            
            overflow /= 10;
        }
        
        return ans ? ans : new ListNode(0);
    }
    
    stack < int > listToStack(ListNode* node) {
        stack < int > ans;
        
        while (node) {
            ans.push(node->val);
            node = node->next;
        }
        
        return ans;
    }
};