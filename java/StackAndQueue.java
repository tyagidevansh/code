class StackImpl {
    int top;
    int max_size = 100;
    int[] arr = new int[max_size];

    StackImpl() {
        top = -1;
    }

    void push(int val) {
        if (top == max_size - 1) {
            System.out.println("Stack overflow!");
            return;
        }

        arr[++top] = val;
        System.out.println(val + " pushed into the stack");
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

class QueueImpl {
    int front, rear, size;
    int capacity = 100;
    int[] array = new int[capacity];

    public QueueImpl() {
        front = size = 0;
        rear = capacity - 1;
    }

    boolean isFull(QueueImpl queue) {
        return (queue.size == queue.capacity);
    }

    boolean isEmpty(QueueImpl queue) {
        return (queue.size == 0);
    }

    void enqueue(int item) {
        if (isFull(this))
            return;
        this.rear = (this.rear + 1) % this.capacity;
        this.array[this.rear] = item;
        this.size = this.size + 1;
        System.out.println(item + " enqueued to queue");
    }

    int dequeue() {
        if (isEmpty(this))
            return Integer.MIN_VALUE;

        int item = this.array[this.front];
        this.front = (this.front + 1) % this.capacity;
        this.size = this.size - 1;
        return item;
    }

    int front() {
        if (isEmpty(this))
            return Integer.MIN_VALUE;

        return this.array[this.front];
    }

    int rear() {
        if (isEmpty(this))
            return Integer.MIN_VALUE;

        return this.array[this.rear];
    }
}

public class StackAndQueue {
    public static void main(String args[]) {
        // Stack demonstration
        StackImpl stack = new StackImpl();
        stack.push(15);
        stack.push(20);
        stack.push(45);
        stack.push(50);

        stack.pop();
        stack.pop();
        System.out.println("Top element of stack: " + stack.peek());

        // Queue demonstration
        QueueImpl queue = new QueueImpl();
        queue.enqueue(5);
        queue.enqueue(4);
        queue.enqueue(3);
        queue.enqueue(2);

        System.out.println(queue.dequeue() + " dequeued from queue");
        System.out.println("Front item is " + queue.front());
        System.out.println("Rear item is " + queue.rear());
    }
}
