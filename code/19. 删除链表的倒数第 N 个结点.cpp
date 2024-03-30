/*
给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

 

示例 1：


输入：head = [1,2,3,4,5], n = 2
输出：[1,2,3,5]
示例 2：

输入：head = [1], n = 1
输出：[]
示例 3：

输入：head = [1,2], n = 1
输出：[1]
 

提示：

链表中结点的数目为 sz
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
 

进阶：你能尝试使用一趟扫描实现吗？
*/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* tmp = head;
        int k = 0;
        while (tmp != NULL) {
            cout << k << endl;
            k = ++k;   
            tmp = tmp->next;
        }

        k = k - n - 1;
        cout << k << endl;
        tmp = head;
        for (int i = 0; i < k; i++) {
            tmp = tmp->next;
        }
        ListNode* tmp2 = tmp->next;
        if (tmp2 == NULL) {  //长度为1
            delete tmp;
            head = NULL;
        } else if (tmp2->next != NULL) { //其他
            tmp->next = tmp2->next;
            delete tmp2;
        } else {  //删除最后一个
            delete tmp->next;
            tmp->next = NULL;
        }

        return head;
    }
};