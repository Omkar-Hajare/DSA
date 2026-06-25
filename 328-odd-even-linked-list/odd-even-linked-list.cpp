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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL)
    return head;
        ListNode* odd=head;
        ListNode* slow=head->next;
        vector<int> arr;

      while(odd!=NULL){
        arr.push_back(odd->val);
        if(odd->next){
        odd=odd->next->next;
        }else{
            break;
        }
      }

      ListNode* even=head->next;
      while(even!=NULL){
        arr.push_back(even->val);
        if(even->next){
        even=even->next->next;
        }else{
            break;
        }
      }

      ListNode* temp=head;
      int i=0;
      while(temp!=NULL){
        temp->val=arr[i];
        temp=temp->next;
        i++;
      }

      return head;
    }
};