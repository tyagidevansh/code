import java.util.LinkedList;

class ProducerConsumer {
    private LinkedList<Integer> buffer = new LinkedList<>();
    private final int CAPACITY = 5;

    public void produce() throws InterruptedException {
        int value = 0;
        while (true) {
            synchronized (this) {
                while (buffer.size() == CAPACITY) {
                    wait();
                }
                System.out.println("Producer produced: " + value);
                buffer.add(value++);
                notify();
                Thread.sleep(1000); // Simulate production time
            }
        }
    }

    public void consume() throws InterruptedException {
        while (true) {
            synchronized (this) {
                while (buffer.isEmpty()) {
                    wait();
                }
                int value = buffer.removeFirst();
                System.out.println("Consumer consumed: " + value);
                notify();
                Thread.sleep(1000); // Simulate consumption time
            }
        }
    }
}

public class ProducerConsumerExample {
    public static void main(String[] args) {
        ProducerConsumer pc = new ProducerConsumer();

        Thread producerThread = new ProducerThread(pc);
        Thread consumerThread = new ConsumerThread(pc);

        producerThread.start();
        consumerThread.start();
    }
}

class ProducerThread extends Thread {
    private ProducerConsumer pc;

    public ProducerThread(ProducerConsumer pc) {
        this.pc = pc;
    }

    @Override
    public void run() {
        try {
            pc.produce();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

class ConsumerThread extends Thread {
    private ProducerConsumer pc;

    public ConsumerThread(ProducerConsumer pc) {
        this.pc = pc;
    }

    @Override
    public void run() {
        try {
            pc.consume();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
