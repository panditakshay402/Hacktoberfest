public class Prime{    
 public static void main(String args[]){    
  int i,d=0,flag=0;      
  int n=3;   
  d=n/2;      
  if(n==0||n==1){  
   System.out.println(n+" is not a prime number");      
  }else{  
   for(i=2;i<=d;i++){      
    if(n%i==0){      
     System.out.println(n+" is not a prime number");      
     flag=1;      
     break;      
    }      
   }      
   if(flag==0)  { System.out.println(n+" is a prime number"); }  
  } 
}    
}   
