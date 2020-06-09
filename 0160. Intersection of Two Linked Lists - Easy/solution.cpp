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
    int listLength(ListNode* head) {
        int result = 0;

        while (head) {
            ++result;
            head = head->next;
        }

        return result;
    }

    ListNode* advance(ListNode* node, int pos=1) {
        for (int i = 0; i < pos; ++i) {
            if (node) {
                node = node->next;
            }
        }
        return node;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto lengthA = listLength(headA);
        auto lengthB = listLength(headB);

        if (lengthA > lengthB) {
            headA = advance(headA, lengthA - lengthB);
        } else {
            headB = advance(headB, lengthB - lengthA);
        }

        while (headA != nullptr) {
            if (headA == headB) {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }

        return headA;
    }
};