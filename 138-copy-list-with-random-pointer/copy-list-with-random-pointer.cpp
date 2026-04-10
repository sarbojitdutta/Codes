/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;

        //inserting new copy nodes in between
        Node* temp = head;
        while(temp != NULL){
            Node* CopyNode = new Node(temp -> val);
            CopyNode -> next = temp -> next;
            temp -> next = CopyNode;
            temp = temp -> next -> next;
        }

        //pointing random nodes
        temp = head;
        while(temp != NULL){
            Node* CopyNode = temp -> next;
            if(temp -> random != NULL){
                CopyNode -> random = temp -> random -> next;   
            }
            temp = temp -> next -> next;
        }

        temp = head;
        Node* dummy = new Node(-1);
        Node* res = dummy;

        while(temp != NULL){
            res -> next = temp -> next;
            temp -> next = temp -> next -> next;

            res = res -> next;
            temp = temp -> next;
        }

        return dummy -> next;
    }
};