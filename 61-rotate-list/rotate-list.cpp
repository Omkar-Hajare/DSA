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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        int size = 1;
        ListNode* tail = head;
        while (tail->next != NULL) {
            tail = tail->next;
            size++;
        }
        k = k % size;
        if (k == 0)
            return head;
        tail->next = head;
        int lastnode = size - k;
        ListNode* temp = head;

        for (int i = 1; i < lastnode; i++) {
            temp = temp->next;
        }

        head = temp->next;
        temp->next = NULL;

        return head;
    }
};