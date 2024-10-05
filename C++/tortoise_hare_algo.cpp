// tortoise and harea lgorithm is a famous algorithm used to detect cycle in a linked list

// approach -
// step 1 - create two pointers slow and fast initially pointing to head
// step 2 - slow will move one step at a time , whle fast will move 2 step at a time
// as soon as slow == fast , that confirms that the linked list has a cycle
// if fast or slow pointer becomes null , that means that the linked list has no cycle.


// code
#include<bits/stdc++.h>
using namespace std;

class ListNode{
    public:
    int data;
    ListNode* next;

    ListNode(int data){
        this->data = data;
        this->next = NULL;
    }
};

bool tortoise_hare_algorithm(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(slow != NULL && fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast) return true;
        }
        return false;       
}

int main(){
    
}
