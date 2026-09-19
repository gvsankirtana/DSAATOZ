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
ListNode* collision (ListNode* t1, ListNode* t2,int d){
    while(d){
        d--;
        t2=t2->next;
    }
    while(t1!=t2){
        t1=t1->next;
        t2=t2->next;
    }
    return t1;
}
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //brute force solution use hashing and store the nodes 
        //better solution TC->O(N1+2N2) sc->o(1)
        ListNode* t1 = headA;
        ListNode* t2 = headB;
        int n1=0,n2=0;
        while(t1!=NULL){
            n1++;
            t1=t1->next;
        }
        while(t2!=NULL){
            n2++;
            t2=t2->next;
        }
        if(n1<n2){
            return collision(headA,headB,n2-n1);
        }
        else{
            return collision(headB,headA,n1-n2);
        }
        //optimal solution TC->O(N1+N2) SC->O(1)
        if(headA==NULL || headB == NULL){
            return NULL;
        }
        ListNode* t1 = headA;
        ListNode* t2 = headB;
        while(t1!=t2){
            t1=t1->next;
            t2=t2->next;
            if(t1==t2) return t1;
            if(t1==NULL){
                t1=headB;
            }
            if(t2==NULL){
                t2=headA;
            }
        }
        return t1;
    }
};
