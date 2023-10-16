public class ArrToLL {
    Node head=null;
    Node tail=null;
    class Node{
        int data;
        Node next;
        
        Node(int data){
            this.data=data;
            this.next=null;
        }

    }
    public Node LL(int arr[]){
        for (int i = 0; i < arr.length; i++) {
            Node newNode=new Node(arr[i]);
            if(head==null){
                head=newNode;
                tail=newNode;
            }else{
                tail.next=newNode;
                tail=newNode;
            }
        }
        return head;
    }
    public void printLL(){
        if(head==null)
        {
            System.out.println("list is empty..");
        }
    
        Node currNode=head;
    
        while(currNode!=null){
            System.out.print(currNode.data+" -> ");
            currNode=currNode.next;
        }
    
        System.out.println("null");
    }
    public static void main(String[] args) {
        int arr[]={1,2,3,4,5};
        ArrToLL node=new ArrToLL();
        node.LL(arr);
        node.printLL();

    }
}
