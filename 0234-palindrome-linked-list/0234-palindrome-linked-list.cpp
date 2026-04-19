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
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        while(head){
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        ListNode* first = head;
        ListNode* slow = head;

        while(first != NULL && first -> next != NULL){
            slow = slow->next;
            first = first->next->next;
        }

        ListNode* secondhalf = reverse(slow);
        ListNode* firsthalf = head;

        while(secondhalf){
            if(firsthalf->val != secondhalf->val){
                return false;
            }
            firsthalf = firsthalf->next;
            secondhalf = secondhalf->next;
        }
        return true;

    }
};