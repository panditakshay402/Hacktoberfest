#include<bits/stdc++.h>

struct Node {
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

class Solution{
    public:
    
    int getMiddleOne(Node* head){
        if(((head == NULL)) || (head->next == NULL)) return head;
    // if 2 nodes--- but it is not required because algo handle from 2 nodes
    // if(head->next->next == NULL) return head->next;
    
    Node* fast = head->next;
    Node* slow = head;
    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
        }
        slow = slow->next;
    }
    return slow->data;
    }

    int getMiddle(Node *head)
    {
        return getMiddleOne(head);
    }
};

int main() {
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Node ob;
        cout << ob.getMiddle(head) << endl;
    }
    return 0;
}