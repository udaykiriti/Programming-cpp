// Method 1: Extending the Thread class
class NumberPrinter extends Thread {
    public void run() {
        for (int i = 1; i <= 5; i++) {
            System.out.println("Thread 1 (Extends Thread): " + i);
            try {
                Thread.sleep(100); // Pause for 100ms
            } catch (InterruptedException e) {
                System.out.println(e);
            }
        }
    }
}

// Method 2: Implementing the Runnable interface
class LetterPrinter implements Runnable {
    public void run() {
        char[] letters = {'A', 'B', 'C', 'D', 'E'};
        for (char l : letters) {
            System.out.println("Thread 2 (Implements Runnable): " + l);
            try {
                Thread.sleep(100);
            } catch (InterruptedException e) {
                System.out.println(e);
            }
        }
    }
}

// Shared Resource for Synchronization Example
class Counter {
    private int count = 0;

    // synchronized keyword ensures only one thread accesses this method at a time
    public synchronized void increment() {
        count++;
    }

    public int getCount() {
        return count;
    }
}

public class MultiThreading {
    public static void main(String[] args) throws InterruptedException {
        System.out.println("--- Basic Thread Creation ---");
        
        NumberPrinter t1 = new NumberPrinter();
        Thread t2 = new Thread(new LetterPrinter());

        // Start threads
        t1.start();
        t2.start();

        // join() waits for threads to die before continuing main thread
        t1.join();
        t2.join();
        System.out.println("Basic threads finished.\n");

        System.out.println("--- Synchronization Example ---");
        Counter counter = new Counter();

        // Using Lambdas for cleaner Runnable implementation
        Thread t3 = new Thread(() -> {
            for(int i = 0; i < 1000; i++) counter.increment();
        });

        Thread t4 = new Thread(() -> {
            for(int i = 0; i < 1000; i++) counter.increment();
        });

        t3.start();
        t4.start();

        t3.join();
        t4.join();

        // Without synchronization, count would be < 2000 due to race conditions
        System.out.println("Final Count (Should be 2000): " + counter.getCount());
    }
}