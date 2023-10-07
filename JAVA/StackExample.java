import java.util.Stack;

public class StackExample {
    public static void main(String[] args) {
        // Creating a stack
        Stack<String> stack = new Stack<>();

        // Pushing elements onto the stack
        stack.push("Element 1");
        stack.push("Element 2");
        stack.push("Element 3");

        // Popping elements from the stack
        String poppedElement = stack.pop();
        System.out.println("Popped Element: " + poppedElement);

        // Peeking at the top element without removing it
        String topElement = stack.peek();
        System.out.println("Top Element: " + topElement);

        // Checking if the stack is empty
        boolean isEmpty = stack.isEmpty();
        System.out.println("Is Stack Empty? " + isEmpty);

        // Printing the elements of the stack
        System.out.println("Stack Elements: " + stack);

        // Getting the size of the stack
        int size = stack.size();
        System.out.println("Stack Size: " + size);
    }
}
