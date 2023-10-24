class LinkedList {
    public class Node{
        int data;
        Node next;
        Node(int data)
        {
            this.data=data;
            this.next=null;
        }
    }
    public static Node head;
    public static Node tail;
    public static int size;
    public void print()
    {
        if(head==null)
        {
            System.out.println("List is Empty");
            return;
        }

        Node temp=head;
        while(temp!=null)
        {
            System.out.print(temp.data+"->");
            temp=temp.next;
        }
        System.out.println("null");
    }
    public void addFirst(int data)
    {
        Node newNode=new Node(data);
        if(head==null)
        {
            head=tail=newNode;
            size++;
            return;
        }
        newNode.next=head;
        head=newNode;
        size++;
    }
    public  void addLast(int data)
    {
        Node newNode=new Node(data);
        if(head==null)
        {
            head=tail=newNode;
            size++;
            return;
        }
        tail.next=newNode;
        tail=newNode;
        size++;
    }
    public void addmid(int idx,int data)
    {
        if(idx==0)
        {
            addFirst(data);
            return;
        }

        Node newNode=new Node(data);
        Node temp=head;
        int i=0;
        while(i<idx-1)
        {
            temp=temp.next;
            i++;
        }
        size++;
        newNode.next=temp.next;
        temp.next=newNode;
    }

    public  int rmvFirst() {
        if (size == 0) {
            System.out.println("LL is empty");
            return Integer.MIN_VALUE;
        } else if (size == 1)
        {
            int val = head.data;
            head = tail = null;
            size=0;
            return val;
        }
        int val=head.data;
        head=head.next;
        size--;
        return val;
    }
    public int rmvlast()
    {
        if (size == 0) {
            System.out.println("LL is empty");
            return Integer.MIN_VALUE;
        } else if (size == 1)
        {
            int val = head.data;
            head = tail = null;
            size=0;
            return val;
        }
        Node pre=head;
        for(int i=0;i<size-2;i++)
        {
            pre=pre.next;
        }
        int val= pre.next.data;
        pre.next=null;
        tail=pre;
        size--;
        return val;

    }
    public void deletenthnodefromend(int n)
    {
        int s=0;
        Node t=head;
        while(t!=null)
        {
            t=t.next;
            s++;
        }
        if(n==s)
        {
            head=head.next;//removeFirst;
            size--;
            return;
        }
        //s-n
        int i=1;
        int itofind=s-n;
        Node pre=head;

        while(i<itofind)
        {
            pre=pre.next;
            i++;
        }
        size--;
        pre.next=pre.next.next;
        return;

    }



    ///Slow=Fast Approach
    public Node findmid(Node head)
    {
        Node slow=head;
        Node fast=head;
        while (fast != null && fast.next != null)
        {
            slow=slow.next;
            fast=fast.next.next;
        }
        return slow;
    }
    public  boolean Linklistpailendrom()
    {
        if(head==null || head.next==null)
            return true;
        //step 1:find mid;
        Node mid=findmid(head);


        //step 2:reverse 2nd half
        Node pre=null;
        Node curr=mid;
        Node next;
        while(curr!=null)
        {
            next=curr.next;
            curr.next=pre;
            pre=curr;
            curr=next;
        }
        Node right=pre;//right half head
        Node left=head;

        //step 3:Check left and right half
        while(right!=null)
        {
            if(left.data!= right.data)
            {
                return  false;
            }
            left=left.next;
            right=right.next;
        }
        return true;
    }
    public void rmvtarget(int n)
    {
        int s=0;
        Node t=head;
        while(t!=null)
        {
            t=t.next;
            s++;
        }
        if(s==n)
        {
            head=head.next;
            return;
        }
        int i=1;
        int itoFind=s-n;
        Node pre=head;
        while(i<itoFind)
        {
            pre=pre.next;
            i++;
        }
        pre.next=pre.next.next;
        return;
    }
    public static void main(String arg[])
    {
        LinkedList ll=new LinkedList();
        ll.addFirst(2);
        ll.addFirst(1);
        ll.addLast(4);
        ll.addLast(5);
        ll.addmid(2,3);
        ll.print();
        ll.rmvtarget(4);
        ll.print();
    }
}