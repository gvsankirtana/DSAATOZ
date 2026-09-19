class Solution {
public:

    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;

        while (left != NULL && right != NULL) {
            if (left->val < right->val) {
                temp->next = left;
                temp = left;
                left = left->next;
            }
            else {
                temp->next = right;
                temp = right;
                right = right->next;
            }
        }

        if (left)
            temp->next = left;
        else
            temp->next = right;

        return dummyNode->next;
    }

    ListNode* sortList(ListNode* head) {

        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* middle = middleNode(head);

        ListNode* lefthead = head;
        ListNode* righthead = middle->next;

        middle->next = NULL;

        lefthead = sortList(lefthead);
        righthead = sortList(righthead);

        return merge(lefthead, righthead);
    }
};
