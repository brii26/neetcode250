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
        unordered_map<Node*,Node*> hmap;
        if (!head) return head;
        Node* head_clone = new Node(head->val);
        Node* curr = head;
        // copy initial node;
        Node* prev = head_clone;
        hmap.insert({curr,prev});
        curr = curr->next;

        // copy only the next list of pointers
        while (curr) {
            Node* new_node = new Node(curr->val);
            prev->next = new_node;
            hmap.insert({curr,new_node});
            prev = new_node;
            curr = curr->next;
        }

        // copy the random so nothing points to a nullptr initially
        Node* curr2 = head;
        Node* curr_clone = head_clone;
        while (curr2) {
            if (curr2->random == nullptr) {
                curr_clone->random = nullptr;
            } else {
                curr_clone->random = hmap[curr2->random];
            }
            curr2 = curr2->next;
            curr_clone = curr_clone->next;
        }
        return head_clone;
    }
};
