class Stack {
    int size = 100;
    int[] stack = new int[100];
    int idx;

    Stack() {
        idx = -1;
    }

    void push(int data) {
        if (idx == size) {
            System.out.println("Stack overflow!");
            return;
        }
        idx++;
        stack[idx] = data;
        System.out.println(data + " pushed into the stack"); 
    }

    int pop() {
        if (idx == -1) {
            System.out.println("Stack underflow!");
            return -1;
        }
        int val = stack[idx];
        idx--;
        return val;
    }

    int peek() {
        return stack[idx];
    }
}

class Queue {
    int capacity = 100;
    int[] queue = new int[capacity];
    int front, rear, size;

    Queue() {
        front = size = 0;
        rear = -1;
    }

    void enqueue(int data) {
        rear++;
        queue[rear] = data;
        size++;

        System.out.println(data + " added to the queue");
    }

    int dequeue() {
        if (size == 0) {
            System.out.println("Queue is empty");
            return -1;
        }
        size--;
        int val = queue[front];
        front++;
        return val;
    }

}

public class StackAndQueue {
    public static void main(String[] args) {
        Stack stack = new Stack();
        stack.push(1);
        stack.push(2);
        System.out.println(stack.pop());
        System.out.println(stack.pop());

        Queue queue = new Queue();
        queue.enqueue(1);
        queue.enqueue(2);
        System.out.println(queue.dequeue());
        System.out.println(queue.dequeue());
    }
}