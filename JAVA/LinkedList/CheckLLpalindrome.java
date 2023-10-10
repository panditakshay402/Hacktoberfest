import java.util.*;
class CheckLLpalindrome {
        int num;
        CheckLLpalindrome next;
        Node(int val) {
            num = val;
            next = null;
        }
}
class EXP{
static CheckLLpalindrome insertNode(CheckLLpalindrome head,int val) {
    CheckLLpalindrome newCheckLLpalindrome = new Node(val);
    if(head == null) {
        head = newNode;
        return head;
    }
    
    CheckLLpalindrome temp = head;
    while(temp.next != null) temp = temp.next;
    
    temp.next = newNode;
    return head;
}

static boolean isPalindrome(CheckLLpalindrome head) {
    ArrayList<Integer> arr=new ArrayList<>();
    while(head != null) {
        arr.add(head.num);
        head = head.next;
    }
    for(int i=0;i<arr.size()/2;i++) 
        if(arr.get(i) != arr.get(arr.size()-i-1)) return false;
    return true;
}

public static void main(String args[]) {
    CheckLLpalindrome head = null;
    head=insertNode(head,1);
    head=insertNode(head,2);
    head=insertNode(head,3);
    head=insertNode(head,2);
    head=insertNode(head,1);
    if(isPalindrome(head)==true)
    System.out.println("True"); 
    else
    System.out.println("False");
    
}
}
