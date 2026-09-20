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
    ListNode* reverseList(ListNode* head) {
      if(head==NULL||head->next==NULL){
        return head;
    }
    ListNode* newhead = reverseList(head->next);
    ListNode* front = head->next;
    front->next = head;
    head->next = NULL;
    return newhead;
    }
    ListNode* findkthnode(ListNode* temp, int k){
        k--;
        while(temp!=NULL&&k>0){
            k--;
            temp = temp->next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevnode = NULL;
        while(temp!=NULL){
            ListNode* kthnode = findkthnode(temp,k);
            if(kthnode==NULL){
                if(prevnode){
                    prevnode->next = temp;
                }
                break;
            }
            ListNode* nextnode = kthnode->next;
            kthnode->next=NULL;
            kthnode = reverseList(temp);
            if(temp==head){
                head=kthnode;
            }
            else{
                prevnode->next = kthnode;
            }
            prevnode = temp;
            temp = nextnode;
        }
        return head;
    }
};
