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
    ListNode* rev(ListNode* head){
        ListNode* curr = head, *prev = NULL, *next;

        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    void reorderList(ListNode* head) {
        ListNode* slow = head, *fast = head;
        while (fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* revH = rev(slow->next);
        slow->next = nullptr;

        ListNode* firstH = head;
        ListNode* secondH = revH;


        while(secondH){
            ListNode* t1 = firstH->next;
            ListNode* t2 = secondH->next;

            firstH->next = secondH;
            secondH->next = t1;

            firstH = t1;
            secondH = t2;
        }

    }
};