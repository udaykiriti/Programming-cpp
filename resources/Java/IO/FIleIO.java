import java.io.*;
import java.util.*;

public class FIleIO {
    public static final boolean DEBUG = true;
    public static void main(String[] args) throws Exception {
        if (DEBUG) {
            System.setIn(new FileInputStream("in.txt"));
            System.setOut(new PrintStream(new FileOutputStream("out.txt")));
            System.out.println("====================Compilation Done=======================");
        }

        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        while (t-- > 0) {
            long start = System.nanoTime(); 

            int n = in.nextInt();
            for (int i = 0; i < n; i++)
                System.out.print(i + " ");
            System.out.println();

            long end = System.nanoTime(); 
            double TotalTime = (end - start) / 1_000_000.0;

            if (DEBUG)
                System.out.printf("Time taken: %.3f ms\n", TotalTime);
        }
    }
}
