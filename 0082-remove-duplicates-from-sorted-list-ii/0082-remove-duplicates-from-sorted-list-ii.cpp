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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode* prevNode = dummy;
        ListNode* currNode = head;

        while(currNode != NULL){
            if(currNode->next != NULL && currNode->val == currNode->next->val){
                int duplicateNode = currNode -> val;

                while(currNode != NULL && currNode -> val == duplicateNode){
                    currNode = currNode -> next;
                }
                prevNode -> next = currNode;
            }else{
                prevNode = prevNode -> next;
                currNode = currNode -> next;
                
            }
            
        }
        return dummy -> next;
        
    }
};