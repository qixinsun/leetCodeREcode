
/*
面试题 02.07. 链表相交
*/
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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int k = 0;
        int y = 0;
        ListNode *tmpa = headA, *tmpb = headB;
        while (tmpa->next != NULL && tmpb->next != NULL) {
            tmpa = tmpa->next;
            tmpb = tmpb->next;
        }

        if (tmpa->next == NULL) {
            while (tmpb->next != NULL) {
                k = ++k;
                tmpb = tmpb->next;
            }

        } else {
            while (tmpa->next != NULL) {
                k = ++k;
                tmpa = tmpa->next;
            }
            y = 1;
        }
        cout << k << endl;
        if (tmpa != tmpb) {
            return NULL;
        }
        tmpa = headA;
        tmpb = headB;

        if (y == 1) {
            for (int i = 0; i < k; i++) {
                tmpa = tmpa->next;
            }
        } else {
            for (int i = 0; i < k; i++) {
                tmpb = tmpb->next;
            }
        }

        while (tmpa != NULL && tmpb != NULL) {
            cout << "jj " << tmpa->val << "  " << tmpb->val << endl;
            if (tmpa == tmpb)
                break;
            else {
                tmpa = tmpa->next;
                tmpb = tmpb->next;
            }
        }
        return tmpa;
    }
};