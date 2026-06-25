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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode (-1);
        ListNode* curr=dummy;
        ListNode* list1=l1;
        ListNode* list2=l2;
        int carry=0;

        while(list1!=NULL || list2!=NULL){
            int sum=carry;

            if(list1) sum+=list1->val;
            if(list2) sum+=list2->val;
            ListNode* newNode=new ListNode(sum%10);
            carry=sum/10;

            curr->next=newNode;
            curr=curr->next;

             if(list1) list1=list1->next;
            if(list2) list2=list2->next;


        }
        if(carry){
            ListNode* newnode=new ListNode(carry);
            curr->next=newnode;
        }

        return dummy->next;
    }
};