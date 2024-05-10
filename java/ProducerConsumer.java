import java.util.concurrent.ArrayBlockingQueue;

class Producer extends Thread {
    private ArrayBlockingQueue<Integer> buffer;

    public Producer (ArrayBlockingQueue<Integer> buffer) {
        this.buffer = buffer;
    }

    public void run() {
        try {
            for (int i = 0; i < 10; i++) {
                buffer.put(i);
                System.out.println("Produced: " + i);
                Thread.sleep(1000);
            }
        } catch(InterruptedException e) {
            e.printStackTrace();
        }
    }
}

class Consumer extends Thread {
    private ArrayBlockingQueue<Integer> buffer;

    public Consumer (ArrayBlockingQueue<Integer> buffer) {
        this.buffer = buffer;
    }

    public void run() {
        try {
            for (int i = 0; i < 10; i++) {
                int item = buffer.take();
                System.out.println("Consumed: " + item);
                Thread.sleep(1100);
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

public class ProducerConsumer {
    public static void main(String[] args) {
        ArrayBlockingQueue<Integer> buffer = new ArrayBlockingQueue<>(5);

        Producer producer = new Producer(buffer);
        Consumer consumer = new Consumer(buffer);

        producer.start();
        consumer.start();

        try {
            producer.join();
            consumer.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}