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
        int carry = 0;
        int sum = 0;
        ListNode dummy = ListNode(0);
        ListNode* ans = &dummy;

        while(l1 && l2){
            sum = carry + l1->val + l2->val;
            carry = sum / 10;
            sum = sum % 10;
            ListNode* new_node = new ListNode(sum);
            ans->next = new_node;
            ans = ans->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1){
            sum = carry + l1->val;
            carry = sum / 10;
            sum = sum % 10;
            ListNode* new_node = new ListNode(sum);
            ans->next = new_node;
            ans = ans->next;
            l1 = l1->next;
        }

        while(l2){
            sum = carry + l2->val;
            carry = sum / 10;
            sum = sum % 10;
            ListNode* new_node = new ListNode(sum);
            ans->next = new_node;
            ans = ans->next;
            l2 = l2->next;
        }

        if(carry == 1){
            ans->next = new ListNode(carry);
        }

        return dummy.next;
    }
};