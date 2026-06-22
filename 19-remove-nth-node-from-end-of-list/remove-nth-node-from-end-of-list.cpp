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
        
        if(head == NULL || head->next == NULL){
            delete head;
            return NULL;
        }

        int length = 0;
        ListNode* temp = head;

        while(temp != NULL){
            length++;
            temp = temp->next;
        }

        // Delete head node
        if(n == length){
            temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        ListNode* trav = head;
        int count = 0;

        while(trav != NULL){
            count++;

            if(count == length - n){
                break;
            }

            trav = trav->next;
        }

        ListNode* reqN = trav->next;

        trav->next = trav->next->next;

        delete reqN;

        return head;
    }
};