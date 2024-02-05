class stack_impl {
    int top;
    int max_size = 100;
    int[] arr = new int[50];

    stack_impl(){
        top = -1;
    }

    void push(int val) {
        if (top == max_size - 1) {
            System.out.println("Stack overflow!");
            return;
        }

        arr[++top] = val;
        System.out.println(val+" pushed into the stack");
    }

    void pop() {
        if (top == -1) {
            System.out.println("Stack underflow!");
            return;
        }
        top--;
        System.out.println("Element popped from stack");
    }

    int peek() {
        if (top == -1) {
            System.out.println("Stack is empty");
            return -1;
        }
        return arr[top];
    }

}

public class stack {
    public static void main(String args[]) {
        stack_impl Stack = new stack_impl();
        Stack.push(10);
        Stack.push(15);
        Stack.push(20);
        Stack.push(30);

        Stack.pop();
        System.out.println("Top element of stack: "+Stack.peek());
    }
}
