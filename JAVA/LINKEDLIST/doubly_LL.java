public class doubly_LL {
    class node{
        public int data;
        public node next;
        public node prev;

        node(int data){
            this.data=data;
            this.next=null;
            this.prev=null;
        }
    } 
    public node head=null;
    public node tail=null;

    public void displaylist(){
        node curr=head;
        if(head==null){
            System.out.println("This given list is empty");
            return;
        }
        System.out.println("data is");
        while(curr!=null){
            System.out.println(curr.data+" ");
            curr=curr.next;
        }
        System.out.println();
    }
    public void reverse(){
        while(tail.next!=null){
            tail=tail.next;
        }
        while(head.prev!=null){
            System.out.print(tail.data+"->");
            tail=tail.prev;
        }
        System.out.print("null");
    }
    public void insert(int data){
        node node1=new node(data);
        if(head==null){
            head=tail=node1;
            tail.next=null;
            head.prev=null;
        }else{
            tail.next=node1;
            node1.prev=tail;
            node1.next=null;
            
        }
    }

    public static void main(String[] args) {
       doubly_LL list=new doubly_LL();
       list.insert(1);
       list.insert(2);
       list.insert(3);

       list.insert(4);
       list.displaylist();

    }
}
