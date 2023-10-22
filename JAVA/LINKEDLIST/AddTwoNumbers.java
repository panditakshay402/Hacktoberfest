

/* node for linked list

class Node {
    int data;
    Node next;

    Node(int d) {
        data = d;
        next = null;
    }
}

*/

class Solution{
    //Function to add two numbers represented by linked list.
    static Node addTwoLists(Node first, Node second){
        // code here
        // return head of sum list
        first=reverseList(first);
        second=reverseList(second);
        int sum=0,carry=0;
        Node dummy = new Node(-1);
        Node temp=dummy;
        while(first!=null || second!=null || carry==1)
        {
            
            if (first != null){
                sum += first.data;
                first = first.next;
            }
            if (second != null){
                sum += second.data;
                second = second.next;
            }
            sum+=carry;
            carry=sum/10;
            Node n=new Node(sum%10);
            temp.next=n;
            temp=temp.next;
            
            sum=0;
        }
         return reverseList(dummy.next); 
       
        
    }
    static Node reverseList(Node head)
    {
        // code here
        Node curr=head;Node prev=null;
        while(curr!=null)
        {
            Node next=curr.next;
            curr.next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
}