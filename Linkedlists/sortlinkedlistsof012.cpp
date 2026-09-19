/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        if(head==NULL||head->next==NULL){
            return head;
        }
        Node* zerohead = new Node(-1);
        Node* onehead = new Node(-1);
        Node* twohead = new Node(-1);
        Node* zero = zerohead;
        Node* one = onehead;
        Node* two = twohead;
        Node* temp = head;
        while(temp!=NULL){
            if(temp->data == 0){
                zero->next = temp;
                zero = temp;
            }
            else if(temp->data==1){
                one->next = temp;
                one = temp;
            }
            else if(temp->data==2){
                two->next = temp;
                two  = temp;
            }
            temp = temp->next;
        }
        zero->next = (onehead->next)?onehead->next:twohead->next;
        one->next = twohead->next;
        two->next = NULL;
        Node* newHead = zerohead->next;
        return newHead;
    }
};
