import java.util.*;

//DEFINITION OF A NODE
class Node{
    int data;
    Node next;

    Node(int data){
        this.data = data;
        this.next = null;
    }
    Node(int data,Node next){
        this.data = data;
        this.next = next;
    }
}

//USER DEFINED LINKED LIST CLASS
class LL{
    private
    Node head;

    public
    LL(){
        this.head = null;
    }

    // INSERTION AT FIRST
    void insert0(int data){
        Node node = new Node(data);
        node.next = head;
        head = node;
    }

    //INSERTION AT LAST
    void insert1(int data){
        Node node = new Node(data);
        if(head == null){
            head = node;
            return;
        }
        Node temp = head;
        while(temp.next != null){
            temp = temp.next;
        }
        temp.next = node;
    }

    //INSERTION AT A PARTICULAR INDEX
    void insert2(int data,int index){
        if(index == 0){
            insert0(data);
            return;
        }
        Node node = new Node(data);
        Node temp = head;
        int count = 1;
        while(temp.next != null && count != index){
            temp = temp.next;
            count++;
        }
        if(count == index){
            node.next = temp.next;
            temp.next = node;
        }else{
            System.out.println(data + " Can't be insert because the index " + index + " doesn't exist");
        }
    }

    //DISPLAY Fn
    void display(){
        Node current = head;
        while(current != null){
            System.out.print(current.data + " ");
            current = current.next;
        }
        System.out.println();
    }
}

public class allCasesOfInsertion{
    public static void main(String[] args){
        LL list = new LL();
        list.insert0(0);
        list.insert0(1);
        list.display();
        list.insert1(3);
        list.insert1(4);
        list.display();
        list.insert2(5, 2);
        list.display();
    }
}